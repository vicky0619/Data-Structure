#include <bits/stdc++.h>
using namespace std;

vector<int> firstLine;

struct node
{
    int data;
    struct node *leftNode;
    struct node *rightNode;
};

struct node *createNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->leftNode = NULL;
    temp->rightNode = NULL;
    return temp;
}

void inorderTraversal(struct node *root)
{
    if (root && root->data != 0)
    {
        inorderTraversal(root->leftNode);
        cout << root->data << " ";
        inorderTraversal(root->rightNode);
    }
}

void levelorderTravelsal(struct node *root)
{
    queue<node *> tempQueue;
    tempQueue.push(root);
    while (!tempQueue.empty())
    {
        struct node *temp = tempQueue.front();
        tempQueue.pop();
        cout << temp->data << " ";
        if (temp->leftNode)
            tempQueue.push(temp->leftNode);
        if (temp->rightNode)
            tempQueue.push(temp->rightNode);
    }
}

struct node *Search(struct node *root, int searchData)
{
    queue<node *> tempQueue;
    tempQueue.push(root);
    while (!tempQueue.empty())
    {
        struct node *temp = tempQueue.front();
        tempQueue.pop();
        if (temp->data == searchData)
            return temp; // found
        if (temp->leftNode)
            tempQueue.push(temp->leftNode);
        if (temp->rightNode)
            tempQueue.push(temp->rightNode);
    }
    return NULL;
}

void reverseTree(struct node *node)
{
    if (node)
    {
        struct node *left = node->leftNode;
        struct node *right = node->rightNode;
        // swap
        node->rightNode = left;
        node->leftNode = right;
        reverseTree(node->leftNode);
        reverseTree(node->rightNode);
    }
}

int main()
{
    string inputLine;
    int count = 0, inputData;
    struct node *root = NULL;
    struct node *temp = NULL;
    queue<node *> Queue;

    getline(cin, inputLine);
    istringstream iss(inputLine);
    while (iss >> inputData)
    {
        firstLine.push_back(inputData);
    }
    root = createNode(firstLine[count++]);
    Queue.push(root);
    // first line
    while (!Queue.empty() && (count != firstLine.size()))
    {
        temp = Queue.front();
        Queue.pop();
        // left
        if (count != firstLine.size())
        {
            temp->leftNode = createNode(firstLine[count++]);
            Queue.push(temp->leftNode);
        }
        else
            break;
        // right
        if (count != firstLine.size())
        {
            temp->rightNode = createNode(firstLine[count++]);
            Queue.push(temp->rightNode);
        }
        else
            break;
    }
    while (cin >> inputData)
    {
        temp = Search(root, inputData);
        reverseTree(temp);
    }
    levelorderTravelsal(root);
    
    return 0;
}