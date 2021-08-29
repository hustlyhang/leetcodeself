/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
public:
    int part[3];
    ParkingSystem(int big, int medium, int small) {
        part[0] = big;
        part[1] = medium;
        part[2] = small;
    }
    
    bool addCar(int carType) {
        switch (carType)
        {
        case 1:
            if (part[0]) {part[0]--; return true;}
            break;
        case 2:
            if (part[1]) {part[1]--; return true;}
            break;
        case 3:
            if (part[2]) {part[2]--; return true;}
            break;
        default:
            return false;
            break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

