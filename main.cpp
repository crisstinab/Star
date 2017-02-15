#include <iostream>
#include <List.h>
#include <Node.h>
#include <string>

using namespace std;

int main()
{
    List<string> *list = new List<string>("A");
    list->insertElement("B");
    list->printList();

    list->removeElement("A");
    list->printList();

    list->removeElement("B");
    list->printList();

    list->insertElement("CC");
    list->insertElement("A");
    list->printList();
}

