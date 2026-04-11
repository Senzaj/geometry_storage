#include <format>
#include <iostream>
#include <memory>
#include <vector>

#include "Calculator/AreaCalculator.h"
#include "Calculator/PerimeterCalculator.h"
#include "Libs/sqlite3.h"
#include "Shapes/Circle.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Triangle.h"

std::vector<std::shared_ptr<Shape>> initFigures();
void testSqlite3(Circle* circle, Rectangle* rectangle, Triangle* triangle);
void printFiguresParams(Circle* circle, Rectangle* rectangle, Triangle* triangle);

int main() {
    std::vector<std::shared_ptr<Shape>> shapes = initFigures();
    testSqlite3(dynamic_cast<Circle*>(&*shapes[0]),
        dynamic_cast<Rectangle*>(&*shapes[1]),
        dynamic_cast<Triangle*>(&*shapes[2]));
    return 0;
}

void testSqlite3(Circle* circle, Rectangle* rectangle, Triangle* triangle) {
    sqlite3 *db;
    char *err_msg = nullptr;
    int db_rc = sqlite3_open("figures.db", &db);

    if (db_rc != SQLITE_OK) {
        sqlite3_close(db);
        return;
    }

    char *sql = "DROP TABLE IF EXISTS figures;"
                "CREATE TABLE figures(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "type TEXT NOT NULL,"
                "param1 REAL,"
                "param2 REAL,"
                "param3 REAL);";

    db_rc = sqlite3_exec(db, sql, nullptr, nullptr, &err_msg);
    if (db_rc != SQLITE_OK) {
        printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return;
    }

    sqlite3_close(db);
    printf("Table created\n");
    printFiguresParams(circle, rectangle, triangle);
}

std::vector<std::shared_ptr<Shape>> initFigures() {
    std::unique_ptr<AreaCalculator> areaCalc = std::make_unique<AreaCalculator>();
    std::unique_ptr<PerimeterCalculator> perimeterCalc = std::make_unique<PerimeterCalculator>();

    double radius = 4;
    double width = 5;
    double height = 6;
    double a = 3;
    double b = 4;
    double c = 5;

    std::vector<std::shared_ptr<Shape>> shapes;

    auto circle = std::make_shared<Circle>(radius, &*areaCalc, &*perimeterCalc);
    auto rectangle = std::make_shared<Rectangle>(width, height, &*areaCalc, &*perimeterCalc);
    auto triangle = std::make_shared<Triangle>(a, b, c, &*areaCalc, &*perimeterCalc);

    shapes.push_back(circle);
    shapes.push_back(rectangle);
    shapes.push_back(triangle);

    printFiguresParams(&*circle, &*rectangle, &*triangle);
    return shapes;
}

void printFiguresParams(Circle* circle, Rectangle* rectangle, Triangle* triangle) {
    std::cout << std::endl << "FIGURES PERIMETER:" << std::endl;
    std::cout << "Circle perimeter = " << std::format("{:.2f}", circle->getPerimeter()) << std::endl;
    std::cout << "Rectangle perimeter = " << std::format("{:.2f}", rectangle->getPerimeter()) << std::endl;
    std::cout << "Triangle perimeter = " << std::format("{:.2f}", triangle->getPerimeter()) << std::endl;
    std::cout << std::endl << "FIGURES AREA:" << std::endl;
    std::cout << "Circle area = " << std::format("{:.2f}", circle->getArea()) << std::endl;
    std::cout << "Rectangle area = " << std::format("{:.2f}", rectangle->getArea()) << std::endl;
    std::cout << "Triangle area = " << std::format("{:.2f}", triangle->getArea()) << std::endl;
    std::cout << std::endl;
}
