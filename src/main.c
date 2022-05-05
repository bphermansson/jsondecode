/**
 * @file main.c
 * @author Patrik
 * @brief Test with json decoder Jansson. 
 *          https://github.com/akheron/jansson
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) Patrik Hermansson 2022
 * 
 */

#include <string.h>
#include <jansson.h>
#define URL_SIZE 256

int main(int argc, char *argv[])
{
    size_t i=0;
    json_error_t error;
    char *text;
    const char *key;
    json_t *obj, *root, *item;
    
    text="{ \"_id\" : { \"$oid\" : \"6241ba3e93c90c266c7e2032\" }, \"Hello\" : \"world!\" }";
    root = json_loads(text, 0, &error);   

    char* toprint;
    toprint = json_dumps(root, 0);
    printf("json_dumps: %s\n", text);

    toprint = json_dumps(root, JSON_INDENT(4)); 
    printf("With indent: %s\n\n", toprint);
    free(toprint); 

    if(!root)
    {
        fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
        return 1;
    }

    if(!json_is_object(root))
    {
        fprintf(stderr, "Error: commit data %ld is not an object\n", i + 1);
        json_decref(root);
    }
    else 
    {
        fprintf(stderr, "Commit data %ld is an object\n", i + 1);
    }
        
    json_object_foreach(root, key, obj)
    {
        printf("Found key '%s'\n", key);
        item = json_object_get(root, key);
        const char *strText;
        strText = json_string_value(item);
        printf("%s : %s\n", key, strText);
    }
    json_decref(root);
}