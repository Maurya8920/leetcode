class MyLinkedList {
public:

    class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get(int index) {
        if(index < 0 || index >= size)
            return -1;

        Node* temp = head;

        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->data;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }

        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void addAtIndex(int index, int val) {

        if(index < 0 || index > size)
            return;

        if(index == 0) {
            addAtHead(val);
            return;
        }

        if(index == size) {
            addAtTail(val);
            return;
        }

        Node* temp = head;

        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }


    void deleteAtIndex(int index) {

        if(index < 0 || index >= size)
            return;


        // delete head
        if(index == 0) {

            Node* temp = head;

            head = head->next;

            if(head == NULL)
                tail = NULL;

            delete temp;

            size--;
            return;
        }


        Node* temp = head;

        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }


        Node* deleteNode = temp->next;

        temp->next = deleteNode->next;


        // deleting tail node
        if(deleteNode == tail)
            tail = temp;


        delete deleteNode;

        size--;
    }
};