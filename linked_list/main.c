#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "list.h"

int main(int argc, char * argv[]) {
    printf("Test New, InsertEnd, ToString, Free\n");
    Node * l = ListNew();
    l = ListInsertEnd(l, 1);
    l = ListInsertEnd(l, 2);
    l = ListInsertEnd(l, 3);
    char * s = ListToString(l);
    assert(strcmp(s," 1 2 3")==0);
    free(s);
    ListDestroy(l);
    
    printf("Test InsertStart\n");
    l = ListNew();
    l = ListInsertStart(l, 3);
    l = ListInsertStart(l, 2);
    l = ListInsertStart(l, 1);
    s = ListToString(l);
    assert(strcmp(s," 1 2 3")==0);
    free(s);
    ListDestroy(l);

    printf("Test RemoveStart\n");
    l = ListNew();
    l = ListInsertStart(l, 3);
    l = ListInsertStart(l, 2);
    l = ListInsertStart(l, 1);
    l = ListRemoveStart(l);
    s = ListToString(l);
    assert(strcmp(s," 2 3")==0);
    free(s);
    l = ListRemoveStart(l);
    s = ListToString(l);
    assert(strcmp(s," 3")==0);
    free(s);
    l = ListRemoveStart(l);
    s = ListToString(l);
    assert(strcmp(s,"")==0);
    free(s);
    ListDestroy(l);

    printf("Test RemoveEnd with InsertStart\n");
    l = ListNew();
    l = ListInsertStart(l, 3);
    l = ListInsertStart(l, 2);
    l = ListInsertStart(l, 1);
    l = ListRemoveEnd(l);
    s = ListToString(l);
    assert(strcmp(s," 1 2")==0);
    free(s);
    l = ListRemoveEnd(l);
    s = ListToString(l);
    assert(strcmp(s," 1")==0);
    free(s);
    l = ListRemoveEnd(l);
    s = ListToString(l);
    assert(strcmp(s,"")==0);
    free(s);
    ListDestroy(l);

    printf("Test RemoveEnd with InsertEnd\n");
    l = ListNew();
    l = ListInsertEnd(l, 1);
    l = ListInsertEnd(l, 2);
    l = ListInsertEnd(l, 3);
    l = ListRemoveEnd(l);
    s = ListToString(l);
    assert(strcmp(s," 1 2")==0);
    free(s);
    l = ListRemoveEnd(l);
    s = ListToString(l);
    assert(strcmp(s," 1")==0);
    free(s);
    l = ListRemoveEnd(l);
    s = ListToString(l);
    assert(strcmp(s,"")==0);
    free(s);
    ListDestroy(l);

    printf("Test Reverse\n");
    l = ListNew();
    l = ListInsertEnd(l, 1);
    l = ListInsertEnd(l, 2);
    l = ListInsertEnd(l, 3);
    l = ListReverse(l);
    s = ListToString(l);
    assert(strcmp(s," 3 2 1")==0);
    free(s);
    ListDestroy(l);

    printf("All tests passed!\n\n");
    return 0;
}

