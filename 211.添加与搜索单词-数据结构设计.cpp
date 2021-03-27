/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() 
    {
        root = new Node();
    }

    ~WordDictionary()
    {
        if (root)
            delete root;
    }

    struct Node
    {
    public:
        Node() : chnode_(26, nullptr), end_(false) {}
        ~Node() 
        {
            for (auto&ptr : chnode_)
            {
                if (ptr)
                    delete ptr;
            }
        }
        
        std::vector<Node*> chnode_;
        bool end_;
    };
    
    void addWord(string word) 
    {
        Node* cur = root;
        Node* next = root;
        for (const auto&ch : word)
        {
            int index = ch - 'a';
            if (index >= 0 && index < 26)
            {
                if (next->chnode_[index] == nullptr)
                    next->chnode_[index] = new Node();
                cur = next;
                next = next->chnode_[index];
            }
        }
        cur->end_ = true;
    }
    
    bool search(string word) 
    {
        if (word.empty())
            return false;
        return findChar(word, 0, root);
    }

    bool findChar(const string& word, int word_index, Node* cur)
    {
        if (static_cast<int>(word.size()) <= word_index || cur == nullptr)
            return false;
        bool flag = false;
        if (word[word_index] == '.')
        {
            for (auto&ptr : cur->chnode_)
            {
                if (ptr != nullptr)
                {
                    if (static_cast<int>(word.size()) == word_index + 1)
                        flag = true;
                    else
                        flag = findChar(word, word_index + 1, ptr);
                    if (flag)
                        break;
                }
            }
        }
        else
        {
            int index = word[word_index] - 'a';
            cur = cur->chnode_[index];
            if (cur != nullptr && static_cast<int>(word.size()) == word_index + 1)
                flag = true;
            else
                flag = findChar(word, word_index + 1, cur);
        }
        return flag;
    }

    Node* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

