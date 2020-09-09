#define ALPHABET_SIZE 26

typedef struct trie_node
{
    int count;   // 记录该节点代表的单词的个数
    trie_node *children[ALPHABET_SIZE]; // 各个子节点
}* trie;

trie_node* create_trie_node()
{
    trie_node* pNode = new trie_node();
    pNode->count = 0;
    for(int i=0; i<ALPHABET_SIZE; ++i)
        pNode->children[i] = nullptr;
    return pNode;
}

void trie_insert(trie root, const string& key)
{
    trie_node* node = root;
    for (int i = 0; i < key.length() ;i++) {
        if(node->children[key[i] -'a'] == nullptr)
        {
            node->children[key[i] -'a'] = create_trie_node();
        }
        node = node->children[key[i] -'a'];
    }
    node->count += 1;
}

int trie_search(trie root, const string& key)
{
    trie_node* node = root;
    int i = 0;
    while(i < key.length()) {
        node = node->children[key[i]-'a'];
        if (node == nullptr) {
            break;
        }
        i++;
    }
    return i;
}


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        trie root = create_trie_node();
        sort(words.begin(), words.end(), [](const string& lhs, const string& rhs) { return lhs.length() > rhs.length(); });
        int res = 0;
        for (const string& word : words) {
            string reverse_word = word;
            reverse(reverse_word.begin(), reverse_word.end());
            if(trie_search(root, reverse_word) < reverse_word.length()) {
                trie_insert(root, reverse_word);
                res += reverse_word.length() + 1;
            }
        }
        return res;
    }
};