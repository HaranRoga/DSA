// a class for storing vertics data
// it contains the folowing objects:
// - data: object to be stored
// - dests: list of available destinations, arrows exits from the vertic
// - unChecked: number of elements to check

#include <iostream>
#include <vector>

using namespace::std;

template <class T> class Vertex
{
private:
    // data saved by the vertex
    T data;
    // pointer to connected vertics
    vector<Vertex*> dests;
    int unChecked;
public:
    // constructor and destructor
    Vertex(T d);
    ~Vertex();

    T getData();
    // add destination to the chain
    void addDest(Vertex* dest);
    bool isChecked();
    // checking if vertics are strong connected
    // true means last chained element equals the first
    bool isCircle(vector<Vertex*>& chain);
};

// constructor receives vertex data to store in the objecet
// also initialize pointers
template <class T> Vertex<T>::Vertex(T d)
{
    data = d;
    dests.clear();
    unChecked = 0;
}

// object destructor
template <class T> Vertex<T>::~Vertex()
{
}

// retrieve the data
template <class T> T Vertex<T>::getData()
{
    return data;
}

// adds new destination to current vertics
template <class T> void Vertex<T>::addDest(Vertex* dest)
{
    dests.push_back(dest);
    unChecked++;
}

// determines if there's anymore unchecked destinations
template <class T> bool Vertex<T>::isChecked()
{
    return (unChecked == 0);
}

// connect vertics to a chain according to destinations
// and checks if they make circle
template <class T> bool Vertex<T>::isCircle(vector<Vertex<T>*>& chain)
{
    // unChecked > 0 check using original chain, add the destinations
    if(unChecked > 0)
    {
        int pos = chain.size();
        unChecked--;
        Vertex* v = dests[unChecked];
        chain.push_back(v);
        bool isHead = v->isCircle(chain);
        // true answer means that circle completed from first element to last
        if(isHead)
        {
            // when there are still destinations to process
            // they shuld be inserted to pos.
            if(unChecked > 0)
            {
                vector<Vertex<T>*> subConnection;
                subConnection.push_back(this);
                unChecked--;
                Vertex* v = dests[unChecked];
                subConnection.push_back(v);
                // if circle complete in the subchain
                if(v->isCircle(subConnection))
                {
                    auto st = subConnection.begin() + 1;
                    auto en = subConnection.end();
                    auto itr = chain.insert(chain.begin() + pos, st, en);               
                }
                else
                {
                    return false;
                }
             }
             // no more destinations to process, return ture
            return true;
        }
        // false answer from isCircle - return false
        return false;
    }
    // when no more connections available, compare current vertex to first element in the chain
    // when they are the same, it means circle complete
    else if(chain[0] == this)
    {
        return true;
    }
    // when different, means dead end
    return false;
}

int main()
{
    Vertex<char> ch1('a');
    Vertex<char> ch2('b');
    Vertex<char> ch3('c');
    Vertex<char> ch4('d');

    ch1.addDest(&ch2);
    ch1.addDest(&ch1);
    ch1.addDest(&ch3);
    ch2.addDest(&ch1);
    ch3.addDest(&ch4);
    ch4.addDest(&ch1);

    vector<Vertex<char>*> vc;
    vc.push_back(&ch3);
    bool b = ch3.isCircle(vc);
    cout << "connet returns: " << b << endl;

    for(Vertex<char>* ch : vc)
    {
        cout << ch->getData() << " ";
    }
    cout << endl;
    cout << "length of chain: " << vc.size();
    return 0;
}