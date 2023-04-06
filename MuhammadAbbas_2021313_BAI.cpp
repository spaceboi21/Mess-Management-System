#include <iostream>
using namespace std;

class WordNode
{
public:
    string word;
    string meaning;
    WordNode *next;
    WordNode(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        next = NULL;
    }
};

class Oxford
{
public:
    WordNode *head;
    Oxford()
    {
        head = NULL;
    }
    void insert(string word, string meaning)
    {
        WordNode *newNode = new WordNode(word, meaning);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            WordNode *temp = head;
            WordNode *prev = NULL;
            while (temp != NULL && word > temp->word && word != temp->word)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                prev->next = newNode;
            }
            else if (word == temp->word)
            {
                char choice;
                cout << "This words already exists do you want to add: (y/n)";
                cin >> choice;
                if (choice == 'y')
                {
                    while (temp != NULL && (meaning > temp->meaning))
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                    if (temp == NULL)
                    {
                        prev->next = newNode;
                    }
                    else if (prev == NULL)
                    {
                        newNode->next = head;
                        head = newNode;
                    }
                    else
                    {
                        newNode->next = temp;
                        prev->next = newNode;
                    }
                }
            }
            else if (prev == NULL)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                newNode->next = temp;
                prev->next = newNode;
            }
        }
    }
    void search(string word)
    {
        WordNode *temp = head;
        while (temp != NULL && temp->word != word)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Word does not exist" << endl;
        }
        else
        {
            while (temp != NULL && temp->word == word)
            {
                cout << temp->word << " : " << temp->meaning << endl;
                temp = temp->next;
            }
        }
    }
    void traverse()
    {
        WordNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->word << " : " << temp->meaning << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Delete(string word)
    {
        WordNode *temp = head;
        WordNode *prev = NULL;
        WordNode *temp2;
        WordNode *temp3;
        while (temp != NULL && temp->word != word)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Word does not exist" << endl;
        }
        else
        {
            WordNode* temp1 = temp;
            temp3 = temp;
            
            
            int count = 0;
            while (temp3 != NULL && temp3->word == word)
            {

                temp3 = temp3->next;
                
                count++;
            }
            if(count > 1)
            {
                string del_meaning;
                temp2 = temp1;
                for(int i = 0; i < count; i++)
                {
                    cout << temp1->meaning << endl;
                    temp1 = temp1->next;
                }
                cout << "Enter the meaning you want to delete" << endl;
                cin >> del_meaning;
                while(temp2-> meaning !=del_meaning)
                {
                    prev = temp2;
                    temp2 = temp2->next;
                    
                }
                if(temp2 == head)
                {
                    head = head-> next;
                }
                else
                {
                    prev->next = temp2->next;
                    temp2 = NULL;
                }   
            }
            else
            {
                if(prev==NULL)
                {
                    head = head->next;
                }
                else
                {
                    prev->next = temp->next;
                    temp = NULL;
                }
            }
        }
    }
    void recursive(WordNode* temp) {
        if (temp==NULL) {
            return;
        }
        recursive(temp->next);
        cout<<temp->word<<" : "<<temp->meaning<<" ";
    }
};


class Char
{
public:
    char alphabet;
    Oxford *dict;
    Char *next;
    Char(char alphabet)
    {
        this->alphabet = alphabet;
        dict = NULL;
        next = NULL;
    }
};

class Alphabets
{
public:
    Char *head;
    Alphabets()
    {
        head = NULL;
    }
    void insert(string word, string meaning)
    {
        char ch = word[0];
        Char *temp = head;
        Char *prev = NULL;
        Char *newNode = new Char(ch);
        Oxford *dictionary = new Oxford();
        dictionary->insert(word, meaning);
        newNode->dict = dictionary;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        while (temp != NULL && ch > temp->alphabet && temp->alphabet != ch)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            prev->next = newNode;
        }
        else if (temp->alphabet == ch)
        {
            temp->dict->insert(word,meaning);
        }
        else if (prev == NULL)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = temp;
            prev->next = newNode;
        }
    }
    void search(string word) {
        Char *temp=head;
        while (temp!=NULL && temp->alphabet!=word[0]) {
            temp=temp->next;
        }
        if (temp==NULL) {
            cout<<"Word does not exist"<<endl;
        } else {
            temp->dict->search(word);
        }
    }
    void traverse() {
        Char* temp = head;
        while(temp!= NULL)
        {
            cout << temp->alphabet << " = ";
            temp->dict->traverse();
            temp=temp->next;
        }
        cout << endl;
    }
    void Delete(string word)
    {
        Char *temp=head;
        while (temp!=NULL && temp->alphabet!=word[0]) {
            temp=temp->next;
        }
        if (temp==NULL) {
            cout<<"letter does not exist"<<endl;
        } else {
            temp->dict->Delete(word);
        }
    }
    void recursive(Char *temp) {
        if (temp==NULL) {
            return;
        }
        recursive(temp->next);
        cout<<temp->alphabet<<" ";
        temp->dict->recursive(temp->dict->head);
    }
};

int main()
{
    Alphabets l;
   l.insert("apple","company");
   l.insert("atlanta","sea");
   l.insert("apple","fruit");
   //l.traverse();
   //l.Delete("apple");
   l.traverse();
   l.recursive(l.head);
//    l.reverse_print(l.head);
}



/*
QUESTION 3
a) The first method is better in time complexity as it will take O(log base 2 n) for it to complete and since second method takes 
O(n+k) it will take more time. Even though k is the number of letters it will take only O(n) as k can be neglected, for all
operations.

b) Method 1 will take approximately 10.344 microseconds to complete the search, whereas method 2 will take 1300 microseconds
to search the same word. Therefore I can conclude that Method 1 is better in sense of time complexity as it is far more efficient
than method 2.
*/