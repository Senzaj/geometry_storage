#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../Shapes/Shape.h"
#include "../Libs/sqlite3.h"

class DatabaseManager {
public:
    explicit DatabaseManager(const std::string& fileName);
    ~DatabaseManager();

    bool initTable();
    bool saveShape(Shape* shape);
    bool loadShape(int id);
    std::vector<std::shared_ptr<Shape>> loadAllShapes();
private:
    sqlite3* db;
    bool executeQuery(const std::string& sql);
};

