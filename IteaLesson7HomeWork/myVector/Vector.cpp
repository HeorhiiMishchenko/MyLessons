#include "Vector.h"

Vector::Vector(int size) {
    size_ = size;
    vectorOfData_ = new int [size_]{};
}

Vector::~Vector() {
    delete[] vectorOfData_;
}

int Vector::max() {
    int max = *vectorOfData_;

    for (int i{ 1 }; i < size_; i++) {
        if (vectorOfData_[i] > max)
        max = vectorOfData_[i];
    }

    return max;
}

int Vector::min() {
    int min = *vectorOfData_;

    for (int i{ 1 }; i < size_; i++) {
        if (vectorOfData_[i] < min)
        min = vectorOfData_[i];
    }

    return min;
}

void Vector::sort() {
    if (size_ <= 0) {
        std::cout << "Size of vector is 0! It's impossible to sort vector!" << std::endl;       //checking that the vector is not empty
        return;
    }

    std::sort(vectorOfData_, vectorOfData_ + size_);
}

void Vector::swap( int firstElement, int secondElement ) {
    if (size_ <= 0) {
        std::cout << "Size of vector is 0! Swapping is impossible!" << std::endl;           //checking that the vector is not empty
        return;
    }

    if (firstElement < size_ && secondElement < size_) {                                    //checking that the element number is within the vector
        std::swap(vectorOfData_[firstElement], vectorOfData_[secondElement]);
    } else
        std::cout << "One or both of the elements are not within the vector!" << std::endl;


}

void Vector::resize( int size ) {
    int* temp = vectorOfData_;

    int it = size < size_ ? size : size_;
    size_ = size;
    
    vectorOfData_ = new int[size_]{};

    for (int i{}; i < it; i++) {
        vectorOfData_[i] = temp[i];
    }
}

int Vector::front() {
    return *vectorOfData_;
}

int Vector::back() {
    return vectorOfData_[size_ - 1];
}

void Vector::printVector() {
    if (size_ <= 0) {
        std::cout << "Size of vector is 0! It's impossible to print vector!" << std::endl;      //checking that the vector is not empty
        return;
    }

    for (int i{}; i < size_; i++) {
        std::cout << vectorOfData_[i] << " ";
    }
    std::cout << std::endl;
}


void Vector::pushBack( int value ) {
    resize(size_ += 1);
    vectorOfData_[size_ - 1] = value;
}

void Vector::append( int value, int position ) {
    if (position >= size_) {                                                                    //checking that the element's position is within the vector
        std::cout << "It's non-existent position!" << std::endl;
        return;
    }

    int* temp = vectorOfData_;
    vectorOfData_ = new int[size_ += 1]{};

    for (int i{}; i < position; i++) {
        vectorOfData_ [i] = temp[i];
    }

    vectorOfData_[position] = value;

    for (int i{ position + 1 }; i < size_; i++) {
        vectorOfData_[i] = temp[i - 1];
    }
}

int Vector::size() {
    return size_;
}

void Vector::clear() {
    size_ = 0;
    delete[] vectorOfData_;
}
