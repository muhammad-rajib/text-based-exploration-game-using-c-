#pragma once

#include <string>
#include <iostream>

#include "Location.h"

using namespace std;

const int ROW_COUNT = 10;
const int COLUMN_COUNT = 10;

typedef unsigned int NodeValue;

const NodeValue MAX_DESCRIPTION_COUNT = 1000;

const NodeValue INACCESSIBLE = 0;
const NodeValue START_MESSAGE = 1;
const NodeValue END_MESSAGE = 2;
const NodeValue DEATH_NODE = 3;
const NodeValue START_NODE = 4;
const NodeValue VICTORY_NODE = 5;
const Location NO_SUCH_VALUE(-1, -1);



class World {

    private:
        NodeValue nodes [ROW_COUNT][COLUMN_COUNT];
        string descriptions[MAX_DESCRIPTION_COUNT];
        unsigned int description_count;

    private:
        void loadNodes (const string& filename);
        void loadDescriptions (const string& filename);
        bool isInvariantValue () const; // new in A3
        bool isInvariantTrue () const;

    public:
        World (const string& game_name);

        void debugPrint () const;
        bool isValid (const Location& location) const;
        bool isDeath (const Location& location) const;
        bool isVictory (const Location& location) const;
        bool canGoNorth (const Location& location) const;
        bool canGoSouth (const Location& location) const;
        bool canGoEast (const Location& location) const;
        bool canGoWest (const Location& location) const;
        Location getNorth (const Location& location) const;
        Location getSouth (const Location& location) const;
        Location getEast (const Location& location) const;
        Location getWest (const Location& location) const;
        Location getStart () const;
        void printStartMessage () const;
        void printEndMessage () const;
        void printDescription (const Location& location) const;
};
