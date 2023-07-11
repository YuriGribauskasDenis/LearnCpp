
#include <iostream>
#include <memory>

using namespace std;

class AudioConpressor
{
public:
    void compress() const {
        cout << "audio compressed" << endl;
    }
};

class VideoConpressor
{
public:
    void compress() const {
        cout << "video compressed" << endl;
    }
};

class SystemApp
{
public:
    SystemApp (
            unique_ptr<AudioConpressor> acompr,
            unique_ptr<VideoConpressor> vcompr
        ) : m_acompr(move(acompr)), m_vcompr(move(vcompr)) {}
    void compress() const {
        m_acompr->compress();
        m_vcompr->compress();
    }
private:
    unique_ptr<AudioConpressor> m_acompr;
    unique_ptr<VideoConpressor> m_vcompr;
};

void clientCode(SystemApp& facade) {
    facade.compress();
}

int main() {
    unique_ptr<AudioConpressor> AC(new AudioConpressor());
    unique_ptr<VideoConpressor> VC(new VideoConpressor());
    unique_ptr<SystemApp> SA(new SystemApp(move(AC), move(VC)));
    
    clientCode(*SA);

    
    return 0;
}