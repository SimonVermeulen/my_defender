/*
** EPITECH PROJECT, 2021
** JSONPARSER
** File description:
** json include file
*/

#ifndef JSON_PARSER_H_
    #define JSON_PARSER_H_

#include <stdio.h>
#include "linked_list.h"

    #define is_number(c) (c >= '0' && c <= '9') ? 1 : 0

    #define is_printable(c) (c > 32 && c < 127) ? 1 : 0

/*****************PARSING*****************/

/**
* @brief launches the parsing of the file at the given path
*
* @param path the path to the file
* @return list_t* the list with all data parsed 
*/
list_t *launch_parsing(char *path);

/**
* @brief Get the content of the JSON file at path 
*
* @param path the path to the JSON file
* @return char* Content of the JSON file 
*/
char *get_buffer(char *path);

/**
* @brief Stringifies the JSON content
*
* @param buffer the buffer to stringify
* @return int 1 if error 0 if no error
*/
int stringify(char **buffer);

/**
* @brief Extracts the data from the given stringify buffer
*
* @param buffer the stringified buffer you need to extract the data from
* @return list_t* the data extracted stocked in a linked list
*/
list_t *get_data(char *buffer);

/*----------TYPE_CHECKERS-----------*/

/**
* @brief gets the type of the current index of the buffer in the node tmp.
* @details
* - 1 if it's an object
* - 2 if it's a double
* - 3 if it's an int
* - 4 if it's a string
* type* 10 if it's an array
*
* @param buff the stringified buffer to check
*
* @param tmp the node to fill with the type
*/
void check_type(const char *buff, node_t *tmp);

/**
* @brief check if the data at the current index of buffer is an array in JSON
*
* @param buff the buffer to check
* @return int 1 if it's an array 0 if not
*/
int check_array(const char *buff);

/**
* @brief check if the data at the current index of buffer is an object in JSON
*
* @param buff the buffer to check
* @return int 1 if it's an object 0 if not
*/
int check_object(const char *buff);

/**
* @brief check if the data at the current index of buffer is a double in JSON
*
* @param buff the buffer to check
* @return int 1 if it's a double 0 if not
*/
int check_double(const char *buff);

/**
* @brief check if the data at the current index of buffer is an int in JSON
*
* @param buff the buffer to check
* @return int 1 if it's an int 0 if not
*/
int check_int(const char *buff);

/**
* @brief check if the data at the current index of buffer is a string in JSON
*
* @param buff the buffer to check
* @return int 1 if it's a string 0 if not
*/
int check_string(const char *buff);

/*----------VALUE_GETTERS-----------*/

/**
* @brief Gets the value contained at the given index of buffer and stocks it in tmp 
*
* @param buffer the buffer to get the value from
* @param index the current index to get value from
* @param tmp the node to stock value in
* @return int the index after reading the value
*/
int get_value(const char *buffer, int index, node_t *tmp);

/**
* @brief Get the key of the current data in buffer
*
* @param buffer the buffer to get the key from
* @param index the current index to get key from
* @param tmp the node to stock value in
* @return int the index after reading the value
*/
int get_key(const char *buffer, int index, node_t *tmp);

/**
* @brief Get the array from the current index of buffer
*
* @param buffer the buffer to get the array values from
* @param index the current index to get the array values from
* @param tmp the node to stock the array in
* @return int the index after reading the array values
*/
int get_array(const char *buff, node_t *new_node, int nb_elements);

/**
* @brief Get the object from the current index of buffer
*
* @param buffer the buffer to get the object values from
* @param index the current index to get the object values from
* @param tmp the node to stock the object in
* @return int the index after reading the object
*/

int get_object(const char *buff, node_t *new_node, int nb_elements);

/**
* @brief Get the double from the current index of buffer
*
* @param buffer the buffer to get the double from
* @param index the current index to get the double from
* @param tmp the node to stock the double in
* @return int the index after reading the double
*/
int get_double(const char *buff, node_t *new_node, int nb_elements);

/**
* @brief Get the int from the current index of buffer
*
* @param buffer the buffer to get the int from
* @param index the current index to get the int from
* @param tmp the node to stock the int in
* @return int the index after reading the int
*/
int get_int(const char *buff, node_t *new_node, int nb_elements);

/**
* @brief Get the string from the current index of buffer
*
* @param buffer the buffer to get the string from
* @param index the current index to get the string from
* @param tmp the node to stock the string in
* @return int the index after reading the string
*/
int get_string(const char *buff, node_t *new_node, int nb_elements);

/*****************WRITING*****************/

/** 
* @brief writes in a given path a json object
*
* @param path the path to the new json file
* @param src the list containings the data to write
* @return int -1 if error 0 if no errors
*/
int launch_write_file(char *path, list_t *src);

/**
* @brief handles the buffer where we writes the datas
*
* @param c the char to add
* @param new_line 1 if you want a newline or 0 if not
* @param fp the file descriptor to the file
*/
void buffer_handler(char c, int new_line, FILE *fp);

/**
* @brief handles the indentation in the json_files
*
* @param level the level of indentation
* @param fp the file descriptor to the file
*/
void write_level(int level, FILE *fp);

/**
* @brief writes the given key
*
* @param key the key to write in buffer
* @param fp the file descriptor of the file
*/
void write_key(char *key, FILE *fp);

/**
* @brief writes the current_node data in the file
*
* @param current_node the current_node to write
* @param level the level of indentation
* @param fp the file descriptor to the file
*/
void write_value(node_t *current_node, int level, FILE *fp);

/**
* @brief writes a given object in the file
*
* @param src the list_t containing the data
* @param level the level of indentation
* @param fp the fp;
*/
void write_object(list_t *src, int level, FILE *fp);

/**
* @brief writes a given double from current_node
*
* @param current_node the node containing the double
* @param level the level of indentation
* @param fp the file descriptor to the file
*/
void write_double(node_t *current_node, int level, FILE *fp);

/**
* @brief writes a given int from current_node
*
* @param current_node the node containing the int
* @param level the level of indentation
* @param fp the file descriptor to the file
*/
void write_int(node_t *current_node, int level, FILE *fp);

/**
* @brief writes a given string from current_node
*
* @param current_node the node containing the string
* @param level the level of indentation
* @param fp the file descriptor to the file
*/
void write_string(node_t *current_node, int level, FILE *fp);

/*****************UTILS*****************/

/**
* @brief frees a json object
*
* @param object the list_t containing the json object to free
* @param recursive 1 for recursive 0 elseway
* @return int 0 if no problems 1 if error
*/
int free_json_object(list_t *object, int recursive);

#endif
