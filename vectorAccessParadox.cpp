
#include <iostream>
#include <vector>
#include <string>

class CLocation
{
public:
    CLocation() = delete;
    CLocation(int id, const std::string& name) : _Id{id}, _Name{name} {}
    void PrintLocation() const {
        std::cout << _Id << " " << _Name << std::endl;
    }
    const int& GetId() const {return _Id;}
    const std::string& GetName() const {return _Name;}
    void SetId(int id) {_Id = id;}
    void SetName(const std::string name) {_Name = name;}
private:
    int _Id;
    std::string _Name;
};

class GameState
{
public:
    GameState() {}
    ~GameState() {
        for (CLocation* location : _Locations) {
            delete location;
        }
        std::cout << std::endl;
    }
    void Append(int id, std::string name) {
        _Locations.push_back(new CLocation(id, name));
    }
    std::vector<CLocation*>& AccessLocations() {return _Locations;}
    const std::vector<CLocation*>& GetLocations() const {return _Locations;}
    void PrintLocations() const {
        for (const CLocation* location : _Locations) {
            location->PrintLocation();
        }
        std::cout << std::endl;
    }
private:
    std::vector<CLocation*> _Locations;
};

int main()
{
    {
        GameState gs;
        gs.Append(0, "Gandia");
        gs.Append(1, "Sitches");
        gs.Append(2, "Cunit");
        gs.PrintLocations();
        std::cout << "=============" << std::endl;
        for (CLocation* location : gs.GetLocations()) {
            location->SetId(42);
        }
        gs.PrintLocations();
        std::cout << "=============" << std::endl;
        for (CLocation* location : gs.AccessLocations()) {
            location->SetName("ShitHole");
        }
        gs.PrintLocations();
    }

    return 0;
}
