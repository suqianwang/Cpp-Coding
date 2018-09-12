//
//  data.h
//  Temperature Queries
//
//  Created by Susan Wang on 4/19/17.
//  Copyright © 2017 Suqian Wang. All rights reserved.
//

#ifndef data_h
#define data_h
class Data {
private:
    int location;
    int year;
    int month;
    double temperature;
public:
    Data();
    Data(int location, int year, int month, double temperature);
    void setLocation(int location);
    int getLocation() const;
    void setYear(int year);
    int getYear() const;
    void setMonth(int month);
    int getMonth() const;
    void setTemperature(double temperature);
    double getTemperature() const;
};

#endif /* data_h */
