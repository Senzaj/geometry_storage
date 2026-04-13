#pragma once
#include <string>
#include <vector>
#include <memory>

#include "../Factory/ShapeFactory.h"
#include "../Shapes/Shape.h"
#include "../Libs/sqlite3.h"

class DatabaseManager {
public:
    explicit DatabaseManager(const std::string& fileName, ShapeFactory* shapeFactory);
    ~DatabaseManager();

    bool initTable();
    bool saveShape(Shape* shape);
    std::shared_ptr<Shape> loadShape(int id);
    std::vector<std::shared_ptr<Shape>> loadAllShapes();
private:
    sqlite3* db;
    bool executeQuery(const std::string& sql);
    bool prepareStatement(sqlite3_stmt* stmt);
    std::shared_ptr<Shape> extractShape(sqlite3_stmt* stmt);
    ShapeFactory* shapeFactory;
};

