#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double CalculBucket(double requiredLiters, double bucketVolume, double bucketPrice) {
    int bucketCount = static_cast<int>(ceil(requiredLiters / bucketVolume));
    return bucketCount * bucketPrice;
}

string BestOption(double requiredLiters, double price1L, double price3L, double price10L) {
    double costFor1L = CalculBucket(requiredLiters, 1, price1L);
    double costFor3L = CalculBucket(requiredLiters, 3, price3L);
    double costFor10L = CalculBucket(requiredLiters, 10, price10L);

    
    if (costFor1L <= costFor3L && costFor1L <= costFor10L) {
        return "1 Liter";
    }
    else if (costFor3L <= costFor1L && costFor3L <= costFor10L) {
        return "3 Liters";
    }
    else {
        return "10 Liters";
    }
}

int main() {
    double height, width, length, paintConsumption;
    cout << "Enter the height of the room (in meters): ";
    cin >> height;
    cout << "Enter the width of the room (in meters): ";
    cin >> width;
    cout << "Enter the length of the room (in meters): ";
    cin >> length;
    cout << "Enter paint consumption (liters per m^2): ";
    cin >> paintConsumption;

    double price1L, price3L, price10L;
    cout << "Enter the price of a 1 liter bucket: ";
    cin >> price1L;
    cout << "Enter the price of a 3 liter bucket: ";
    cin >> price3L;
    cout << "Enter the price of a 10 liter bucket: ";
    cin >> price10L;

    double S = 2 * height * (width + length);

    double requiredLiters = S * paintConsumption;

    int buckets10L = static_cast<int>(requiredLiters / 10);
    double remainingLiters = requiredLiters - (buckets10L * 10);

    int buckets3L = static_cast<int>(remainingLiters / 3);
    remainingLiters -= buckets3L * 3;

    int buckets1L = static_cast<int>(ceil(remainingLiters));

    if (buckets1L == 3) {
        buckets1L = 0;
        buckets3L++;
    }
    else if (buckets1L > 3) {
        buckets1L = 0;
        buckets3L++;
        if (buckets3L == 3) {
            buckets3L = 0;
            buckets10L++;
        }
    }

    double total = (buckets1L * price1L) + (buckets3L * price3L) + (buckets10L * price10L);

    cout << "Minimum required number of buckets of paint:\n";
    cout << "Buckets of 10 liters: " << buckets10L << endl;
    cout << "Buckets of 3 liters: " << buckets3L << endl;
    cout << "Buckets of 1 liter: " << buckets1L << endl;
    cout << "Total purchase price: " << total << "RUB." << endl;

    string bestOption = BestOption(requiredLiters, price1L, price3L, price10L);
    cout << "It is more profitable to buy buckets with the following volume: " << bestOption << endl;

}