#include <iostream>
#include <map>
#include <string>

class AssociationMap {
private:
    std::map<std::string, std::string> associations;
    int codeError;

public:
    AssociationMap() {
        codeError = 0;
    }

    std::string& operator[](const std::string& key) {
        if (associations.count(key) == 0) {
            codeError = -1; // ������������ ��� �������
            // ��������� ��������� �� ������� ����� �� ������������
            return associations[""];
        }
        return associations[key];
    }

    void printAssociations() const {
        for (const auto& pair : associations) {
            std::cout << pair.first << " -> " << pair.second << std::endl;
        }
    }

    friend std::istream& operator>>(std::istream& is, AssociationMap& map) {
        std::string key, value;
        is >> key >> value;
        map.associations[key] = value;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const AssociationMap& map) {
        for (const auto& pair : map.associations) {
            os << pair.first << " -> " << pair.second << std::endl;
        }
        return os;
    }
};

int main() {
    AssociationMap map;

    // ��������� ������������ ���������
    map["google.com"] = "172.217.22.174";
    map["example.com"] = "93.184.216.34";

    // ��������� ������������ ���������
    std::cout << map;

    // ��������� �� ��������
    std::cout << map["google.com"] << std::endl; // ������ "172.217.22.174"
    std::cout << map["nonexistent"] << std::endl; // ������ ������� �����

    // �������� ���� �������
    if (map["nonexistent"].empty()) {
        std::cout << "�������: ³������ �������" << std::endl;
    }

    return 0;
}