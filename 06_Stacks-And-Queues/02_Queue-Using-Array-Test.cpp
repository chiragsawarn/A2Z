#include <cassert>
#include "02_Queue-Using-Array.cpp" // Include your queue implementation

void testQueueOperations() {
    ArrayQueue q(5);

    // Test empty queue
    assert(q.empty() == true);
    assert(q.size() == 0);
    assert(q.front() == -1); // Should print "Queue Empty!" and return -1

    // Test push operation
    q.push(10);
    assert(q.empty() == false);
    assert(q.size() == 1);
    assert(q.front() == 10);

    q.push(20);
    q.push(30);
    assert(q.size() == 3);
    assert(q.front() == 10);

    // Test pop operation
    q.pop();
    assert(q.size() == 2);
    assert(q.front() == 20);

    q.pop();
    assert(q.size() == 1);
    assert(q.front() == 30);

    q.pop();
    assert(q.empty() == true);
    assert(q.size() == 0);

    // Test underflow
    q.pop(); // Should print "Queue Underflown!"

    // Test overflow
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6); // Should print "Queue Overflown!"

    assert(q.size() == 5); // Capacity is 5
    assert(q.front() == 1);

    // Test circular behavior
    q.pop();
    q.push(7);
    assert(q.front() == 2);
    assert(q.size() == 5);
}

int main() {
    testQueueOperations();
    cout << "All tests passed!" << endl;
    return 0;
}