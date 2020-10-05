//=============================================================================
enum
{
    kIsSmaller,
    kIsLarger,
    kIsSame
};

//-
class Data
{
public:
    Data(int newVal) : value(newVal){};
    ~Data(){};
    int compare(const Data &);
    void show() { std::cout << value << "\n"; };

private:
    int value;
};

int Data::compare(const Data &otherData)
{
    if (value < otherData.value)
    {
        return kIsSmaller;
    }
    else if (value > otherData.value)
    {
        return kIsSmaller;
    }
    else
    {
        return kIsSame;
    }
}

//--
class Node;
class HeadNode;
class TailNode;
class InternalNode;

//-
class Node
{
public:
    Node(){};
    virtual ~Node(){};
    virtual Node *insert(Data *data) = 0;
    virtual void show() = 0;

private:
};

//-
class InternalNode : public Node
{
public:
    InternalNode(Data *newData, Node *newNode);
    virtual ~InternalNode()
    {
        delete data;
        delete next;
    };
    virtual Node *insert(Data *data);
    virtual void show()
    {   
        std::cout << "- InternalNode show: \n";
        data->show();
        next->show();
    };

private:
    Data *data;
    Node *next;
};

InternalNode::InternalNode(Data *newData, Node *newNode) : data(newData), next(newNode)
{
    std::cout << "Internal Node init \n";
}

Node *InternalNode::insert(Data *otherdata)
{
    std::cout << "x";
    int result = data->compare(*otherdata);
    switch (result)
    {
    case kIsSame:
    case kIsLarger:
    {
        InternalNode *dataNode = new InternalNode(otherdata, this);
        return dataNode;
    }
    case kIsSmaller:
        next = next->insert(otherdata);
        return this;
    }
    
    return this;
}

//-
class TailNode : public Node
{
public:
    TailNode(){};
    virtual ~TailNode(){};
    virtual Node *insert(Data *data);
    virtual void show(){
        std::cout << "- TailNode show: \n";
    };

private:
};

Node *TailNode::insert(Data *data)
{
    std::cout << ">";
    InternalNode *dataNode = new InternalNode(data, this);
    return dataNode;
}

//-
class HeadNode : public Node
{
public:
    HeadNode();
    virtual ~HeadNode() { delete next; };
    virtual Node *insert(Data *data);
    virtual void show() { 
        std::cout << "- HeadNode show: ";
        next->show(); };
private:
    Node *next;
};

HeadNode::HeadNode()
{
    next = new TailNode;
}

Node *HeadNode::insert(Data *data)
{
    next = next->insert(data);
    return this;
}

//-
class LinkedList
{
public:
    LinkedList();
    ~LinkedList(){};
    void insert(Data *data);
    void showAll() { 
        std::cout << "linkedList show: ";
        head->show(); };

private:
    HeadNode *head;
};

LinkedList::LinkedList()
{
    head = new HeadNode;
}

void LinkedList::insert(Data *pdata)
{
    head->insert(pdata);
}