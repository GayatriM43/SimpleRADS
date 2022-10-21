#include "InternalNode.hpp"
#include "LeafNode.hpp"
#include "RecordPtr.hpp"

//creates internal node pointed to by tree_ptr or creates a new one
InternalNode::InternalNode(const TreePtr &tree_ptr) : TreeNode(INTERNAL, tree_ptr) {
    this->keys.clear();
    this->tree_pointers.clear();
    if (!is_null(tree_ptr))
        this->load();
}

//max element from tree rooted at this node
Key InternalNode::max() {
    Key max_key = DELETE_MARKER;
    TreeNode* last_tree_node = TreeNode::tree_node_factory(this->tree_pointers[this->size - 1]);
    max_key = last_tree_node->max();
    delete last_tree_node;
    return max_key;
}

Key InternalNode::min() {
    Key min_key = DELETE_MARKER;
    TreeNode* last_tree_node = TreeNode::tree_node_factory(this->tree_pointers[this->size - 1]);
    min_key = last_tree_node->min();
    delete last_tree_node;
    return min_key;
}

//if internal node contains a single child, it is returned
TreePtr InternalNode::single_child_ptr() {
    if (this->size == 1)
        return this->tree_pointers[0];
    return NULL_PTR;
}

//inserts <key, record_ptr> into subtree rooted at this node.
//returns pointer to split node if exists
//TODO: InternalNode::insert_key to be implemented
TreePtr InternalNode::insert_key(const Key &key, const RecordPtr &record_ptr) {
    TreePtr new_tree_ptr = NULL_PTR;
    //cout << "InternalNode::insert_key not implemented" << endl;
    int ind= this->size-1,i=0;
    for (i = 0; i < this->size - 1; i++) 
    {
        if(key <= this->keys[i])
            {
                ind = i; 
                break;
            }
    } 
    auto* child_node = TreeNode::tree_node_factory(this->tree_pointers[ind]);
    TreePtr new_child_tree_ptr = child_node->insert_key(key, record_ptr);
    if(new_child_tree_ptr != NULL_PTR)
    {
        //TreeNode* new_child = TreeNode::tree_node_factory(new_child_tree_ptr);
        int new_key=child_node->max();
        this->keys.insert(this->keys.begin()+ind,new_key);
        this->tree_pointers.insert(this->tree_pointers.begin()+ind+1,new_child_tree_ptr);
        
        if(this->size==FANOUT)
        {
            InternalNode* split_node = new InternalNode();
            for(i=MIN_OCCUPANCY;i<FANOUT;i++)
            {
                split_node->keys.push_back(this->keys[i]);
                split_node->tree_pointers.push_back(this->tree_pointers[i]);
            }
            split_node->tree_pointers.push_back(this->tree_pointers[i]);
            this->keys.resize(MIN_OCCUPANCY);
            this->tree_pointers.resize(MIN_OCCUPANCY);
            split_node->size = split_node->tree_pointers.size();
            new_tree_ptr= split_node->tree_ptr;
            split_node->dump();
            delete split_node;
        }
         
        //delete new_child;
    }
    this->size=this->tree_pointers.size();
    this->dump();
    delete child_node;
    //cout<<"Size of "<<this->tree_ptr<<" "<<this->size<<"\n";
    return new_tree_ptr;
}

void InternalNode::merge(TreeNode* left_child_node,TreeNode* child_node,int ind)
{
    cout<<"MERGE BETWEEN "<<left_child_node->tree_ptr<<" "<<child_node->tree_ptr<<endl;
    NodeType node_type = child_node -> node_type;
    cout<<node_type<<" MERGE"<<endl;
    if(node_type == LEAF)
    {
        LeafNode* left_child_node_new = (LeafNode*) left_child_node;
        LeafNode* child_node_new = (LeafNode*) child_node;
        map<Key, RecordPtr> new_removed = child_node_new -> pop_elements(0,child_node_new->size);
        left_child_node_new -> push_elements(new_removed);
        left_child_node_new -> next_leaf_ptr = child_node_new -> next_leaf_ptr;
        child_node_new -> delete_node();
        cout<<"All elements of child node:"<<endl;
        for(const auto & it : left_child_node_new->data_pointers)
            cout<<it.first<<" ";
        cout<<endl;
    }
    else
    {
        InternalNode* left_child_node_new = (InternalNode*) left_child_node;
        InternalNode* child_node_new = (InternalNode*) child_node;
        vector<TreePtr> new_removed = child_node_new -> pop_elements(0,child_node_new -> size);
        left_child_node_new -> push_elements(left_child_node_new->size,new_removed,1);
        child_node_new -> delete_node();
        cout<<"All elements of child node:"<<endl;
        for(int i=0;i<left_child_node_new->keys.size();i++)
            cout<<left_child_node_new->keys[i]<<" "<<left_child_node_new->tree_pointers[i]<<" ";
        cout<<endl;
    }
    cout<<"Deleting Key in Internal Node"<<endl;
    cout<<this->keys.size()<<endl;
    this->keys.erase(this->keys.begin() + ind);
    cout<<this->keys.size()<<endl;
    cout<<"Deleted Key in Internal Node"<<endl;
    this->tree_pointers.erase(this->tree_pointers.begin() + ind + 1);
    this->size = this->tree_pointers.size();
    
}
void InternalNode::redist_left(TreeNode* left_child_node,TreeNode* child_node,int ind)
{
    cout<<"Redistribute Left"<<endl;
    NodeType node_type = child_node -> node_type;
    if(node_type == LEAF)
    {
        LeafNode* left_child_node_new = (LeafNode*) left_child_node;
        LeafNode* child_node_new = (LeafNode*) child_node;
        map<Key, RecordPtr> new_removed = left_child_node_new -> pop_elements(left_child_node_new->size-1,left_child_node_new->size);
        child_node_new -> push_elements(new_removed);
        this->keys[ind-1] = left_child_node_new->max();
        this->keys[ind] = child_node_new->max();
    }
    else
    {
        InternalNode* left_child_node_new = (InternalNode*) left_child_node;
        InternalNode* child_node_new = (InternalNode*) child_node;
        vector<TreePtr> new_removed = left_child_node_new -> pop_elements(left_child_node_new->size-1,left_child_node_new->size);
        child_node_new -> push_elements(0,new_removed,0);
        this->keys[ind-1] = left_child_node_new->max();
        this->keys[ind] = child_node_new->max();
    }
}

void InternalNode::redist_right(TreeNode* right_child_node,TreeNode* child_node,int ind)
{
    NodeType node_type = child_node -> node_type;
    if(node_type == LEAF)
    {
        LeafNode* right_child_node_new = (LeafNode*) right_child_node;
        LeafNode* child_node_new = (LeafNode*) child_node;
        map<Key, RecordPtr> new_removed = right_child_node_new -> pop_elements(0,1);
        child_node_new -> push_elements(new_removed);
        this->keys[ind+1] = right_child_node_new->max();
        this->keys[ind] = child_node_new->max();
    }
    else
    {
        InternalNode* right_child_node_new = (InternalNode*) right_child_node;
        InternalNode* child_node_new = (InternalNode*) child_node;
        cout<<right_child_node_new->size<<" "<<child_node_new->size<<endl;
        vector<TreePtr> new_removed = right_child_node_new -> pop_elements(0,1);
        cout<<"Removed Size: "<<new_removed.size()<<endl;
        cout<<"Size There: "<<right_child_node_new->size<<endl;
        child_node_new -> push_elements(child_node_new->size,new_removed,1);
        cout<<"Push done"<<endl;
        cout<<ind<<endl;
        this->keys[ind+1] = right_child_node_new->max();
        this->keys[ind] = child_node_new->max();
    }
    
}

void InternalNode::delete_key(const Key &key) {
    TreePtr new_tree_ptr = NULL_PTR;
    cout << "InternalNode::delete_key for" <<this->tree_ptr<< endl;
    int ind=this->size-1;
    cout<<"Size"<<this->size<<endl;
    for(int i=0;i<this->size-1;i++)
        if(key<=this->keys[i])
        {
            ind = i;
            break;
        }
    TreeNode* child_node = TreeNode::tree_node_factory(this->tree_pointers[ind]);
    TreeNode* left_child_node = ind > 0 ? TreeNode::tree_node_factory(this->tree_pointers[ind-1]):NULL;
    TreeNode* right_child_node = ind < this->size-1 ? TreeNode::tree_node_factory(this->tree_pointers[ind+1]):NULL;
    child_node -> delete_key(key);
    if(child_node->size<MIN_OCCUPANCY)
    {
        if(left_child_node && (left_child_node->size + child_node->size >= 2*MIN_OCCUPANCY))
        {   cout<<"in1"<<endl;
            this->redist_left(left_child_node,child_node,ind);
        }
        else if(left_child_node && (left_child_node->size + child_node->size <=FANOUT))
        {
            cout<<"in2"<<endl;
            this->merge(left_child_node,child_node,ind-1);
        }
        else if(right_child_node && (right_child_node->size + child_node->size >=2*MIN_OCCUPANCY))
        {
            cout<<"in3"<<endl;
            this->redist_right(right_child_node,child_node,ind);
        }
        else if(right_child_node && (right_child_node->size + child_node->size <=FANOUT))
        {
            cout<<"in4"<<endl;
            this->merge(child_node,right_child_node,ind);
        }
    }

    delete child_node;
    delete left_child_node;
    delete right_child_node;

    this->dump();
}

//runs range query on subtree rooted at this node
void InternalNode::range(ostream &os, const Key &min_key, const Key &max_key) const {
    BLOCK_ACCESSES++;
    for (int i = 0; i < this->size - 1; i++) {
        if (min_key <= this->keys[i]) {
            auto* child_node = TreeNode::tree_node_factory(this->tree_pointers[i]);
            child_node->range(os, min_key, max_key);
            delete child_node;
            return;
        }
    }
    auto* child_node = TreeNode::tree_node_factory(this->tree_pointers[this->size - 1]);
    child_node->range(os, min_key, max_key);
    delete child_node;
}

//exports node - used for grading
void InternalNode::export_node(ostream &os) {
    TreeNode::export_node(os);
    for (int i = 0; i < this->size - 1; i++)
        os << this->keys[i] << " ";
    os << endl;
    for (int i = 0; i < this->size; i++) {
        auto child_node = TreeNode::tree_node_factory(this->tree_pointers[i]);
        child_node->export_node(os);
        delete child_node;
    }
}

//writes subtree rooted at this node as a mermaid chart
void InternalNode::chart(ostream &os) {
    string chart_node = this->tree_ptr + "[" + this->tree_ptr + BREAK;
    chart_node += "size: " + to_string(this->size) + BREAK;
    chart_node += "]";
    os << chart_node << endl;

    for (int i = 0; i < this->size; i++) {
        auto tree_node = TreeNode::tree_node_factory(this->tree_pointers[i]);
        tree_node->chart(os);
        delete tree_node;
        string link = this->tree_ptr + "-->|";

        if (i == 0)
            link += "x <= " + to_string(this->keys[i]);
        else if (i == this->size - 1) {
            link += to_string(this->keys[i - 1]) + " < x";
        } else {
            link += to_string(this->keys[i - 1]) + " < x <= " + to_string(this->keys[i]);
        }
        link += "|" + this->tree_pointers[i];
        os << link << endl;
    }
}

ostream& InternalNode::write(ostream &os) const {
    TreeNode::write(os);
    cout<<"Internal Write"<<endl;
    for (int i = 0; i < this->size - 1; i++) {
        if (&os == &cout)
            os << "\nP" << i + 1 << ": ";
        os << this->tree_pointers[i] << " ";
        if (&os == &cout)
            os << "\nK" << i + 1 << ": ";
        os << this->keys[i] << " ";
    }
    if (&os == &cout)
        os << "\nP" << this->size << ": ";
    os << this->tree_pointers[this->size - 1];
    return os;
}

void InternalNode::push_elements(int position,vector<TreePtr> new_pointers,bool right)
{
    int i=0;
    cout<<" Position of inserting is "<<position<<endl;
    for(i=0;i<new_pointers.size();i++)
    {
        TreeNode* new_node = TreeNode::tree_node_factory(new_pointers[i]);
        int ele=new_node->max();
        if(right==1)
            ele=TreeNode::tree_node_factory(tree_pointers[i+position-1])->max();
        if(right==0)
            this->keys.insert(this->keys.begin() + i + position,ele);
        else
            this->keys.insert(this->keys.begin() + i + position-1,ele);
        this->tree_pointers.insert(this->tree_pointers.begin() + i + position,new_pointers[i]);
        this->size++;
        delete new_node;
    }
    this->dump();
}

vector<TreePtr> InternalNode::pop_elements(int start,int end)
{
    vector<TreePtr> to_be_deleted = {};
    to_be_deleted.assign(this->tree_pointers.begin()+start,this->tree_pointers.begin()+end);
    this->tree_pointers.erase(this->tree_pointers.begin()+start,this->tree_pointers.begin()+end);
    for(int i=0;i<tree_pointers.size();i++)
        cout<<tree_pointers[i]<<" ";
    cout<<endl;
    if(tree_pointers.size()==0)
        this->keys.erase(this->keys.begin(),this->keys.end());
    else if(start==0)    
        this->keys.erase(this->keys.begin()+start,this->keys.begin()+end);
    else
        this->keys.erase(this->keys.begin()+start-1,this->keys.begin()+end-1);

    this->size=this->tree_pointers.size();
    cout<<"Size Here: "<<this->size<<endl;
    cout<<"Size Here: "<<to_be_deleted.size()<<endl;
    if(tree_pointers.size()!=0)
        this->dump();
    return to_be_deleted;
}




istream& InternalNode::read(istream& is) {
    TreeNode::read(is);
    this->keys.assign(this->size - 1, DELETE_MARKER);
    this->tree_pointers.assign(this->size, NULL_PTR);
    for (int i = 0; i < this->size - 1; i++) {
        if (&is == &cin)
            cout << "P" << i + 1 << ": ";
        is >> this->tree_pointers[i];
        if (&is == &cin)
            cout << "K" << i + 1 << ": ";
        is >> this->keys[i];
    }
    if (&is == &cin)
        cout << "P" << this->size;
    is >> this->tree_pointers[this->size - 1];
    return is;
}


