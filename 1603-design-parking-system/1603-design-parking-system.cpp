class ParkingSystem {
public:
    int a, b, c;
    ParkingSystem(int big, int medium, int small) {
        a = big;
        b = medium;
        c = small;
    }
    bool valid(int& type) {
        if(type > 0) {
            type--;
            return 1;
        }
        return 0;
    }
    bool addCar(int carType) {
        if(carType == 1)
            return valid(a);
        if(carType == 2)
            return valid(b);

        return valid(c);
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */