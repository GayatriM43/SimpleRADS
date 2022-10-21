#include "RecordPtr.hpp"
#include "LeafNode.hpp"

LeafNode::LeafNode(const TreePtr &tree_ptr) : TreeNode(LEAF, tree_ptr) {
    this->data_pointers.clear();
    this->next_leaf_ptr = NULL_PTR;
    if(!is_null(tree_ptr))
        this->load();
}

//returns max key within this leaf
Key LeafNode::max() {
    auto it = this->data_pointers.rbegin();
    return it->first;
}

Key LeafNode::min() {
    auto it = this->data_pointers.begin();
    return it->first;
}

//inserts <key, record_ptr> to leaf. If overflow occurs, leaf is split
//split node is returned
//TODO: LeafNode::insert_key to be implemented
TreePtr LeafNode::insert_key(const Key &key, const RecordPtr &record_ptr) {
    TreePtr new_leaf = NULL_PTR; //if leaf is split, new_leaf = ptr to new split node ptr
    //cout << "LeafNode:: insert_key not implemented" << endl;
    this->data_pointers.insert(pair<Key,RecordPtr>(key, record_ptr));
    if(this->size == FANOUT)
    {
        //cout<<"Fanout reached\n";
        LeafNode* newLeafNode = new LeafNode(new_leaf);
        new_leaf = newLeafNode -> tree_ptr;
        int co = 0;
        for(const auto & data_pointer : this->data_pointers)
        {
            if(co >= MIN_OCCUPANCY)
            {
                newLeafNode->data_pointers.insert(data_pointer);
                newLeafNode->size ++;
            }
            co += 1;
        }
        // cout<<"S "<<this->size<<endl;
        // cout<<"S1 "<<this->data_pointers.size()<<endl;
        this->data_pointers.erase(next(this->data_pointers.begin(), MIN_OCCUPANCY),this->data_pointers.end());
        this->size = this->data_pointers.size();
        newLeafNode -> next_leaf_ptr = this->next_leaf_ptr;
        this->next_leaf_ptr = new_leaf;
        newLeafNode->dump();
    }
    else
        this->size++;
    //this->size=this->data_pointers.size();
    //cout<<"Reached out of fan node"<<endl;
    //cout<<this->size<<endl;
    this->dump();
    //cout<<"Size of "<<this->tree_ptr<<" "<<this->size<<"\n";
    return new_leaf;
}

//key is deleted from leaf if exists
//TODO: LeafNode::delete_key to be implemented
void LeafNode::delete_key(const Key &key) {
    cout << "LeafNode::delete_key not implemented" << endl;
    this->data_pointers.erase(key);
    this->size--;
    this->dump();
}

//runs range query on leaf
void LeafNode::range(ostream &os, const Key &min_key, const Key &max_key) const {
    BLOCK_ACCESSES++;
    for(const auto& data_pointer : this->data_pointers){
        if(data_pointer.first >= min_key && data_pointer.first <= max_key)
            data_pointer.second.write_data(os);
        if(data_pointer.first > max_key)
            return;
    }
    if(!is_null(this->next_leaf_ptr)){
        auto next_leaf_node = new LeafNode(this->next_leaf_ptr);
        next_leaf_node->range(os, min_key, max_key);
        delete next_leaf_node;
    }
}

//exports node - used for grading
void LeafNode::export_node(ostream &os) {
    TreeNode::export_node(os);
    for(const auto& data_pointer : this->data_pointers){
        os << data_pointer.first << " ";
    }
    os << endl;
}

//writes leaf as a mermaid chart
void LeafNode::chart(ostream &os) {
    string chart_node = this->tree_ptr + "[" + this->tree_ptr + BREAK;
    chart_node += "size: " + to_string(this->size) + BREAK;
    for(const auto& data_pointer: this->data_pointers) {
        chart_node += to_string(data_pointer.first) + " ";
    }
    chart_node += "]";
    os << chart_node << endl;
}

ostream& LeafNode::write(ostream &os) const {
    TreeNode::write(os);
    //cout<<"Write called "<<data_pointers.size()<<endl;
    for(const auto & data_pointer : this->data_pointers){
        //cout<<data_pointer.first<<endl;
        if(&os == &cout)
            os << "\n" << data_pointer.first << ": ";
        else
            os << "\n" << data_pointer.first << " ";
        os << data_pointer.second;
    }
    os << endl;
    os << this->next_leaf_ptr << endl;
    return os;
}

istream& LeafNode::read(istream& is){
    TreeNode::read(is);
    this->data_pointers.clear();
    for(int i = 0; i < this->size; i++){
        Key key = DELETE_MARKER;
        RecordPtr record_ptr;
        if(&is == &cin)
            cout << "K: ";
        is >> key;
        if(&is == &cin)
            cout << "P: ";
        is >> record_ptr;
        this->data_pointers.insert(pair<Key,RecordPtr>(key, record_ptr));
    }
    is >> this->next_leaf_ptr;
    return is;
}

void LeafNode::push_elements(map<Key, RecordPtr> records)
{
    this->data_pointers.insert(records.begin(),records.end());
    this->size=this->data_pointers.size();
    this->dump();
}

map<Key, RecordPtr> LeafNode::pop_elements(int start,int end)
{
    cout<<"POP ELEMENTS LEAF"<<endl;
    map<Key, RecordPtr> mp;
    mp.insert(next(this->data_pointers.begin(),start),next(this->data_pointers.begin(),end));
    cout<<"Insertion Size: "<<mp.size()<<endl;
    this->data_pointers.erase(next(this->data_pointers.begin(),start),next(this->data_pointers.begin(),end));
    this->size=this->data_pointers.size();
    cout<<"Size after deletion: "<<this->size<<endl;
    this->dump();
    return mp;  
}


