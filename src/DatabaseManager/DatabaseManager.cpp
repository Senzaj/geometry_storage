#include <iostream>
#include "DatabaseManager.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Triangle.h"

DatabaseManager::DatabaseManager(const std::string& fileName) : db{nullptr} {
    int rc = sqlite3_open(fileName.c_str(), &db);
    if (rc != SQLITE_OK)
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
}

DatabaseManager::~DatabaseManager() {
    if (db)
        sqlite3_close(db);
}

bool DatabaseManager::executeQuery(const std::string &sql) {
    char* errMsh = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsh);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsh << std::endl;
        sqlite3_free(errMsh);
        return false;
    }

    return true;
}

bool DatabaseManager::initTable() {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS figures(
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        type TEXT NOT NULL,
        param1 REAL,
        param2 REAL,
        param3 REAL,);
    )";

    return executeQuery(sql);
}

bool DatabaseManager::saveShape(Shape *shape) {
    if (!shape)
        return false;

    ShapeType shapeType = shape->getType();
    std::string typeStr = shapeTypeToString(shapeType);
    double p1 = 0, p2 = 0, p3 = 0;

    switch (shapeType) {
        case ShapeType::Circle: {
            if (auto* circle = dynamic_cast<Circle*>(shape)) {
                p1 = circle->getRadius();
            }
            break;
        }
        case ShapeType::Rectangle: {
            if (auto* rect = dynamic_cast<Rectangle*>(shape)) {
                p1 = rect->getWidth();
                p2 = rect->getHeight();
            }
            break;
        }
        case ShapeType::Triangle: {
            if (auto* triangle = dynamic_cast<Triangle*>(shape)) {
                p1 = triangle->getASide();
                p2 = triangle->getBSide();
                p3 = triangle->getCSide();
            }
            break;
        }
        default:
            std::cerr << "Unknown shape type" << std::endl;
            return false;
    }

    const std::string sql = R"(
        INSERT INTO figures(type,param1,param2,param3)
        VALUES(?,?,?,?);)";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, typeStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 2, p1);
    sqlite3_bind_double(stmt, 3, p2);
    sqlite3_bind_double(stmt, 4, p3);

    rc = sqlite3_step(stmt);
    bool success = (rc == SQLITE_DONE);
    if (!success) {
        std::cerr << "Insert failed: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    return success;
}

bool DatabaseManager::loadShape(int id) {

}

std::vector<std::shared_ptr<Shape>> DatabaseManager::loadAllShapes() {
    std::vector<std::shared_ptr<Shape>> shapes;
    std::string sql = "SELECT type, param1, param2, param3 FROM figures";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return shapes;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* type = sqlite3_column_text(stmt, 0);
        double param1 = sqlite3_column_double(stmt, 1);
        double param2 = sqlite3_column_double(stmt, 2);
        double param3 = sqlite3_column_double(stmt, 3);

        std::string typeStr = reinterpret_cast<const char*>(type);
        ShapeType shapeType = stringToShapeType(typeStr);

        switch (shapeType) {
            case ShapeType::Circle:
                shapes.push_back(std::make_shared<Circle>
                    (param1, nullptr, nullptr));
                break;
            case ShapeType::Rectangle:
                shapes.push_back(std::make_shared<Rectangle>
                    (param1, param2, nullptr, nullptr));
                break;
            case ShapeType::Triangle:
                shapes.push_back(std::make_shared<Triangle>
                    (param1, param2, param3, nullptr, nullptr));
                break;
        }
    }

    sqlite3_finalize(stmt);
    return shapes;
}
