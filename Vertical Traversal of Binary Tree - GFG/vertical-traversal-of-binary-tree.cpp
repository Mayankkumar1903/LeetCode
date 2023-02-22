//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        // step1: create a mapping such that corresponding to horizontal distacnce and the level there exists a values in the form of vector
        map<int,map<int,vector<int>>> mapping;
        
        
        // step2: create a queue such that it hold the data like Node and its corresponding horizontal distance and the level 
        queue<pair<Node*,pair<int,int>>> q;
        
        
        
        //step3: create an answer vector of type int to store the values
        vector<int> answer;
        
        
        //step4:if root is NULL then return answer which will obviously be empty
        if(root == NULL)
            return answer;
        
        
        
        
        //step5: push the root element into the queue 
        q.push(make_pair(root,make_pair(0,0)));
        // intially our horizontal distance and level will be 0 for our root Node
        
        
        
        
        //step6: same like level order traversal we take the front Node of the queue, additional to that we will also get the horizontal distance and level corresponding to the frontNode we received and using those values to insert data through horizontal distance and level
        while(!q.empty())
        {
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            mapping[hd][lvl].push_back(frontNode->data);
        //step7: same like level order traversal , if left of the frontNode exists then push it into the queue and do the same for the right on the frontNode 
            if(frontNode->left != NULL)
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
                //if we are going left then decrease horizontal distance by 1 and obviously we should increase level by 1 because we are in next level
            if(frontNode->right != NULL)
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
                //if we are going right then increase horizontal distance by 1 and obviously we should increase level by 1 because we are in next level
        }
        
        
        //step8: insert the values into the answer vector by accessing the members of the map
        for(auto a:mapping)
        {
            // now we are getting 'a' as map<int,map<int,vector<int>>> , we should access vector so we need a.second which gives map<int,vector<int>>
            for(auto b:a.second)
            {
                //now as 'b' we are getting map<int,<vector<int>>>, we should acces vector so we need b.second which gives us vector<int>
                for(auto c:b.second)
                {
                    //now we are getting 'c' as the values or elements of the vector and it is auto incremental so we should just push_back the values into the answer vector
                    answer.push_back(c);
                }
            }
        }
        
        
        
        //step9: return the answer
        return answer;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends