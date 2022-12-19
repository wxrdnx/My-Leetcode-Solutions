class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for (auto& str : strs) {
            encoded += to_string(str.length());
            encoded += ':';
            encoded += str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> list;
        int i = 0;
        while (i < str.length()) {
            int sep = str.find(':', i);
            int size = stoi(str.substr(i, sep - i));
            string decoded = str.substr(sep + 1, size);
            list.push_back(decoded);
            i = sep + 1 + size;
        }
        return list;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
