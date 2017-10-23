/*
  Replace Words

  In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

  Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

  You need to output the sentence after the replacement.

  Example 1:
  Input: dict = ["cat", "bat", "rat"]
  sentence = "the cattle was rattled by the battery"
  Output: "the cat was rat by the bat"
  Note:
  The input will only have lower-case letters.
  1 <= dict words number <= 1000
  1 <= sentence words number <= 1000
  1 <= root length <= 100
  1 <= sentence words length <= 1000

 */

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    vector<TrieNode*> children;
    // isEndOfWord is true if the node represents
    // end of a word
    vector<bool> isEndOfWord;

    TrieNode(): isEndOfWord(vector<bool>(ALPHABET_SIZE, false)), children(vector<TrieNode*>(ALPHABET_SIZE, NULL)) {}

    void insert(string key, int pos) {
        if(pos >= key.length())
            return;
        int index = key[pos] - 'a';
        if(pos == key.length() - 1)
            isEndOfWord[index] = true;
        if(!children[index])
            children[index] = new TrieNode();
        children[index].insert(key, pos + 1);
    }

    int query(string word, int pos) {
        if(pos >= word.length())
            return -1;
        int index = word[pos] - 'a';
        if(isEndOfWord[index])
            return pos;
        if(!children[index])
            return -1;
        return children[index].query(word, pos + 1);
    }
};

string replaceWords(vector<string>& dict, string sentence) {
    TrieNode* root = new TrieNode();
    for(auto key: dict)
        root.insert(key, 0);
    vector<string> words;
    int pos = 0;
    while(pos < sentence.length()) {
        int prev = pos;
        pos = sentence.find(' ', pos);
        if(pos == -1)
            pos = sentence.length();
        string word = sentence.substr(prev, pos - prev);
        words.push_back(word);
        pos++;
    }
    for(auto word: words) {
        int q = root.query(word, 0);
        if(q != -1) {
            string rep = word.substr(0, q + 1);
            word = rep;
        }
    }
    string res = "";
    for(int i = 0; i < words.size(); i++) {
        if(i != words.size() - 1)
            res += words[i] + " ";
        else
            res += words[i];
    }
    return res;
}
