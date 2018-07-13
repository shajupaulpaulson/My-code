#include <openssl/sha.h>
#include <vector>
#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;
class Block {
public:
    string sPrevHash;
 
    Block(uint32_t nIndexIn, const string &sDataIn);
 
    string GetHash();
 
    void MineBlock(uint32_t nDifficulty);
 
private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;
 
    string _CalculateHash() const;
};

class Blockchain {
public:
    Blockchain();
 
    void AddBlock(Block bNew);
 
private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;
 
    Block _GetLastBlock() const;
};
static bool print1=false;
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
 
    string str(cstr);
 
    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);
    cout << "Block mined: " << _sHash << endl;
}
string sha256(string test){
    unsigned char hash[SHA256_DIGEST_LENGTH];
	char outputBuffer[65];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, test.c_str(), sizeof(test));
    SHA256_Final(hash, &sha256);
    int	i = 0;
	
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
	//cout << test<<endl;
	string temp(outputBuffer);
	//string temp = static_cast <char []> (hash);
    return (temp);
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
    if(!print1){
		cout <<ss.str()<<endl;
		print1=true;
	}
    return sha256(ss.str());
}


Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 6;
}

void Blockchain::AddBlock(Block bNew) {
	print1=false;
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
int main() {
    Blockchain bChain = Blockchain();
 
    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Block 1 Data"));
 
    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2 Data"));
 
    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data"));
 
    return 0;
}