class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string,string> mp;
    map<string,string> mp1;
    int k=1;
    string encode(string longUrl) {
        mp[longUrl]=to_string(k);
        mp1[to_string(k)]=longUrl;
        k++;
        return mp[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
      return mp1[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));