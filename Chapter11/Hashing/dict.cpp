#define HASHMAP_SIZE 17

// UM BYTE POSSUI 256 COMBINAÇÕES POSSÍVEIS POIS 2^8 = 256

#include <stdio.h>

namespace Dict
{
    struct LLNode
    {
        LLNode *next;
        char *key;
        void *value;
        int type;
        LLNode(int c_type, void *c_value)
        {
            this->type = c_type;
            this->value = c_value;
            this->next = nullptr;
        }

        int get_type()
        {
            return type;
        }
        /*
         * type 0 = int
         * type 1 = char
         * type 2 = float
         */
        int get_int_value()
        {
            return *((int *)this->value);
        }
        char *get_str_value()
        {
            return (char *)this->value;
        }

        float get_float_value()
        {
            return *((float *)this->value);
        }
    };

    struct LL
    {
        LLNode *head;
        void insert(int type, void *value)
        {
            if (this->head == nullptr)
            {
                LLNode *newNode = new LLNode(type, value);
                this->head = newNode;
                return;
            }

            LLNode *aux = this->head;
            while (aux->next != nullptr)
            {
                aux = aux->next;
            }
            LLNode *n = new LLNode(type, value);
            aux->next = n;
        }
    };
    struct Dict
    {
        LL data[HASHMAP_SIZE];

        void insert(const char *key, int type, void *value)
        {
            int index = this->hashFn(key);
            this->data[index].insert(type, value);
        }

        void printKey(const char *key)
        {
            int index = this->hashFn(key);
            printf("%d \n", index);
            LLNode *head = this->data[index].head;
            LLNode *aux = head;
            while (aux != nullptr)
            {
                switch (aux->get_type())
                {
                case 0:
                    printf("%d ", aux->get_int_value());
                    break;
                case 1:
                    printf("%s ", aux->get_str_value());
                    break;
                case 2:
                    printf("%.2f ", aux->get_float_value());
                    break;
                default:
                    break;
                };
                aux = aux->next;
            }
            printf("\n");
        }

        int hashFn(const char *key)
        {
            return 0;
        }
    };
};

int main(void)
{
    Dict::Dict *dict = new Dict::Dict();
    int integer = 13;
    char string[] = "João";
    float teste = 2.1312321543;
    dict->insert("1", 0, (void *)&integer);
    dict->insert("1", 0, (void *)&integer);
    dict->insert("1", 1, (void *)string);
    dict->insert("1", 2, (void *)&teste);
    dict->printKey("1");
    int value = 0;
}
