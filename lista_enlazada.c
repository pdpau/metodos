#include "lista_enlazada.h"

void init_list(List* list) {
    list->head = 0;
    list->length = 0;
}

Element* create_element(int number) {
    Element* elem = (Element*) malloc(sizeof(Element));
    elem->val = number;
    elem->next = 0;
    return elem;
}
void free_element(Element* elem) {
    free(elem);
}
int length(List* list) {
    return list->length;
}
bool is_empty(List* list) {
    if (list->head == 0 || list->head == NULL) {
        return true;
    } else {
        return false;
    }
}

void add_first(List* list, int num) {
    Element* elem = create_element(num);
    elem->next = list->head;
    list->head = elem;

    list->length++;
}
void add_last(List* list, int num) {
    Element *elem = create_element(num);
    if (is_empty(list)) {
        list->head = elem; // si no hay elementos, lo colocamos como el primero
    } else {
        Element* puntero_especial = list->head; // hay que irlo moviendo hasta que llegue al final de la lista
        while (puntero_especial->next != 0 || puntero_especial->next != NULL) {
            puntero_especial = puntero_especial->next;
        }
        puntero_especial->next = elem; // cuando ya apunta al ultimo elemento, le guardamos el elemento que queremos añadir al final
    }

    list->length++;
}
void add_after(int n, List* list, int num) {
    Element *elem = create_element(num);
    if (is_empty(list)) {
        list->head = elem; // si no hay elementos, lo colocamos como el primero
    } else {
        Element* puntero = list->head;
        int pos = 0;
        while (pos < n && puntero->next) {
            puntero = puntero->next;
            pos++;
        }
        elem->next = puntero->next; // dejamos un hueco para poder insertar justo despues de n (si fuera el ultimo, se asigna un NULL y sin problema)
        puntero->next = elem;
    }

    list->length++;
}

int get_element(int n, List* list) {
    if (is_empty(list)) {
        return -1;
    } else {
        Element* puntero = list->head;
        int pos = 0;
        while (pos < n && puntero->next) {
            puntero = puntero->next;
            pos++;
        }
        if (pos != n) { // si no hay tantos elementos como el numero n pide
            return -1;
        } else {
            return puntero->val;
        }
    }
}

void remove_first(List* list) {
    if (!is_empty(list)) {
        Element* deleted = list->head;
        list->head = list->head->next; // paso el head a la siguiente posicion
        free_element(deleted);
        list->length--;
    }
}
void remove_last(List* list) {
    if (!is_empty(list)) {
        if (length(list) == 1) { // si solo tiene 1 elemento, lo quito directamente
            Element* deleted = list->head;
            list->head = NULL;
            free_element(deleted);
            list->length--;
        } else { // si tiene mas de 1, tengo que recorrer la lista
            Element* puntero = list->head;
            while (puntero->next->next != NULL) { // salimos cuando lleguemos al penultimo elemento
                puntero = puntero->next;
            }
            Element* deleted = puntero->next;  // vamos a eliminar el siguiente del penultimo (el ultimo)
            puntero->next = NULL; // eliminamos el ultimo
            free_element(deleted);
            list->length--;
        }
    }
}
void remove_element(int n, List* list) {
    if (!is_empty(list)) {
        if (n == 0) { //igual que el remove first
            // remove_first(list);
            Element* deleted = list->head;
            list->head = list->head->next;
            free_element(deleted);
            list->length--;
        } else if (n < length(list)){
            Element* puntero = list->head;
            int pos = 0;
            while (pos < (n-1)) { // salgo del bucle en el anterior al que quiero eliminar
                puntero = puntero->next;
                pos++;
            }
            Element* deleted = puntero->next;
            puntero->next = NULL;
            free_element(deleted);
            list->length--;
        }
    }
}

void print_list(List* list) {
    if (!is_empty(list)) {
        for (Element* elem = list->head; elem; elem = elem->next) {
            printf("[%d]", elem->val);
        }
        printf("\n");
    } else {
        printf("[]\n");
    }
}
void clear_list(List* list) {
    if (list->head != NULL) {
        for (Element* elem = list->head, *next; elem; elem = next) {
            next = elem->next;
            free(elem);
        }
        list->head = NULL;
        list->length = 0;
    }
}