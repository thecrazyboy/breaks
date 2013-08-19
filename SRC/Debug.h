#pragma once

typedef struct GraphTrigger
{
    char    *name;
    int     *link;
    int     x, y;
} GraphTrigger;

typedef struct GraphLocator
{
    char    *name;
    int     coord_x, coord_y;
} GraphLocator;

typedef struct GraphCollector
{
    int     width, height;
    int     coord_x, coord_y;
    unsigned (*getter)();
    void    (*setter) (unsigned);
} GraphCollector;

typedef struct DebugContext
{
    char    *tabname;
    char    *image;
    GraphTrigger    *triggers;
    int     num_triggers;
    GraphLocator    *locators;
    int     num_locators;
    GraphCollector  *collectors;
    int     num_collectors;
    void    (*step) ();
} DebugContext;
