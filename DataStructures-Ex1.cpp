#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Car
{
    public:
    int id; // Car's ID number/
    string company; // Chr's company name.
    int year; // Car's year of build.

    /*
        Functionality: The function is the constructor of the car object, and run when a new car element is initialized.
        Input: Gets the year of build of the car (int), company name of the car (pointer to a char array), and the ID of the car (int)
        Output: none.
    */
    Car(int year, string /*char**/ company, int id)
    {
        this->year = year; // Inserts the year inputed to the class variable.
        this->company = company; // Inserts the company name to the class variable.
        this->id = id; // Inserts the id to the class variable.
    }
};

void showError()
{
    cout << "unknown command";
}

// Class to build a do-direction-node chain of Car elements.
class Car_List
{
public:
    Car* key; // The node value - a Car elemnt.
    Car_List* next; // pointer to the next node in the chain.
    Car_List* prev; // pointer to the previous node in chain.

    /*
    Functionality: Constructor to initialize new node in the chain (new CarList object)/
    Input: Gets a pointer to a car element as a input.
    Output: none;
    */
    Car_List(Car* key)
    {
        this->key = key; // Inserts the pointer of the car element to the class variable.
    }
};

// Class that allow us to manage a garage - like Moty's garage and Rami's garage.
class Garage
{
public:
    Car_List* head = NULL; // Pointer to the head of the carlist chain (first object in chain).
    Car_List* tail = NULL; // pOINTER TO THE TAIL OF THE CARLIST CHAIN (Llast object in chain)
    /*
    Functionality:
    Input:
    Output:
    */

    void newCar(int year, string company, int id, int isunion)
    {
        string str = company;
        Car_List* check_car_list = head;
        Car_List* last_node = NULL;
        bool flag = false;
        while (check_car_list !=  NULL && flag == false)
        {
            if (check_car_list->key->id == id)
            {
                cout << "new car ID already exist in M\n";
                return;
            }
            else if (check_car_list->key->id > id)
            {
                flag = true;
            }
            if (!flag)
            {
                last_node = check_car_list;
                check_car_list = check_car_list->next;
            }
        }

        Car* new_car = new Car(year, str, id);
        Car_List* new_node = new Car_List(new_car);
        if (last_node == NULL)
        {
            head = new_node;
            head->prev = NULL;
            head->next = check_car_list;
        }
        else
        {
            new_node->next = check_car_list;
            last_node->next = new_node;
            new_node->prev = last_node;
        }

        if (check_car_list == NULL)
        {
            tail = new_node;
        }
        else
        {
            check_car_list->prev = new_node;
        }

        if (!isunion)
            cout << "new car add successfully to M\n";
    };

    void deleteCar(int id)
    {
        Car_List* check_car_list = head;
        Car_List* last_node = NULL;
        bool flag = false;
        while (check_car_list !=  NULL && flag == false)
        {
            if (check_car_list->key->id == id)
            {
                flag = true;
            }
            else if (check_car_list->key->id > id)
            {
                cout << "no car with given ID in M\n";
                return;
            }
            if (!flag)
            {
                last_node = check_car_list;
                check_car_list = check_car_list->next;
            }
        }

        Car_List* temp = check_car_list;
        if (last_node == NULL)
        {
            head = check_car_list->next;
            if (head != NULL)
                head->prev = NULL;
        }
        else
        {
            last_node->next = check_car_list->next;
            if (check_car_list->next == NULL)
            {
                tail = last_node;
            }
            else
            {
                check_car_list->next->prev = last_node;
            }
        }


        delete temp->key;
        delete temp;

        cout << "car was removed from M\n";
    };

    void findMinimumIdCar()
    {
        cout << "min M ID=" << head->key->id;
    };

    void findMaximumIdCar()
    {
        cout << "max R ID=" << tail->key->id;
    };
};

void print(Garage* g, char  letter);


Garage* ListsUnion(Garage* g1, Garage* g2)
{
    Garage* g3 = new Garage();
    Car_List* pointer_to_g1 = g1->tail;
    Car_List* pointer_to_g2 = g2->tail;

    while (pointer_to_g1 != NULL && pointer_to_g2 != NULL)
    {
        if (pointer_to_g1->key->id < pointer_to_g1->key->id)
        {
            g3->newCar(pointer_to_g1->key->year, pointer_to_g1->key->company, pointer_to_g1->key->id, 1);
            pointer_to_g1 = pointer_to_g1->prev;
        }
        else
        {
            g3->newCar(pointer_to_g2->key->year, pointer_to_g2->key->company, pointer_to_g2->key->id, 1);
            pointer_to_g2 = pointer_to_g2->prev;
        }
    }
    if (pointer_to_g1 == NULL)
    {
        while (pointer_to_g2 != NULL)
        {
            g3->newCar(pointer_to_g2->key->year, pointer_to_g2->key->company, pointer_to_g2->key->id, 1);
            pointer_to_g2 = pointer_to_g2->prev;
        }
    }
    else if (pointer_to_g2 == NULL)
    {
        while (pointer_to_g1 != NULL)
        {
            g3->newCar(pointer_to_g1->key->year, pointer_to_g1->key->company, pointer_to_g1->key->id, 1);
            pointer_to_g1 = pointer_to_g1->prev;
        }
    }

    return g3;
}

Garage* M = new Garage();
Garage* R = new Garage();

    void print(Garage* g, char letter)
    {
        Car_List* temp_pointer = g->head;

        while (temp_pointer != NULL)
        {
            cout << letter << "(" << temp_pointer->key->year << "," << temp_pointer->key->company << "," << temp_pointer->key->id << ")\n";
            temp_pointer = temp_pointer->next;
        }
    }

void checkAction(char* action)
{
    int garage, i=2;
    if (action[0] =='M')
        garage = 0;
    else if (action[0] == 'R')
        garage = 1;
    else
    {
        showError();
        return;
    }
    if (action[1] != '(' && action[1] != '=')
    {
        showError();
        return;
    }
    if (strcmp(action+1, "(find-min)") == 0)
    {
        if (garage == 0)
            M->findMinimumIdCar();
        else if (garage == 1)
            R->findMaximumIdCar();
    }
    else if (strcmp(action+1, "(find-max)") == 0)
    {
        if (garage == 0)
            M->findMaximumIdCar();
        else if (garage == 1)
            R->findMaximumIdCar();
    }
     else if (strcmp(action+1, "(print)") == 0)
    {
        if (garage == 0)
            print(M, 'M');
        else if (garage == 1)
            print(R, 'R');
    }
    else if (strcmp(action, "R=(R,M)") == 0)
    {
        R = ListsUnion(R, M);
    }
    else
    {
        showError();
        return;
    }
}

void insertToList(char* action)
{

    int garage, i = 3, year = 0, id = 0;
    char company[200] = "";
    char temp[2];
    temp[1] = '\0';
    if (action[1] =='M')
        garage = 0;
    else if (action[1] == 'R')
        garage = 1;
    else
    {
        showError();
        return;
    }

    if (action[2] != '(')
    {
        showError();
        return;
    }
    while (action[i] != ',')
    {
        year = year * 10 + (action[i++] - '0');
    }
    i++;
    while (action[i] != ',')
    {
        temp[0] = action[i++];
        strcat(company, temp);
    }
    i++;
    while (action[i] != ')')
    {
       id = id * 10 + (action[i++] - '0');
    }
    i++;
    if (action[i] == '\0')
    {
        if (garage == 0)
        {
            M->newCar(year, company, id, 0);
        }
        else if (garage == 1)
        {
            R->newCar(year, company, id, 0);
        }
    }
    else
    {
        showError();
        return;
    }
}

void deleteFromList(char* action)
{

    int garage, i = 3, id = 0;
    if (action[1] =='M')
        garage = 0;
    else if (action[1] == 'R')
        garage = 1;
    else
    {
        showError();
        return;
    }

    if (action[2] != '(')
    {
        showError();
        return;
    }
    while (action[i] != ')')
    {
        id = id * 10 + (action[i++] - '0');
    }
    i++;
    if (action[i] == '\0')
    {
        if (garage == 0)
        {
            M->deleteCar(id);
        }
        else if (garage == 1)
        {
            R->deleteCar(id);
        }
    }
    else
    {
        showError();
        return;
    }
}

int main()
{
    char action[200];// ??

    cin >> action;

    while (strcmp(action, "99") != 0)
    {
        switch (action[0])
        {
            case '+':
                insertToList(action);
            break;

            case '-':
                deleteFromList(action);
            break;

            default:
                checkAction(action);
            break;
        }

        cin >> action;
    }

    return 0;
}
