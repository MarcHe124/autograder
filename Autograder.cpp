#include "Autograder.h"

/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 */
class AutograderMapper : public Mapper
{
public:
    void Map(Input<Submission> *input)
    {
        while (!input->done())
        {
            float grade = autograding(input->value());

            output(input->value()->studentId, grade);

            input->next();
        }
    }

    float autograding(Submission *submission)
    {
        float result;
        // TODO. run auto grading C# program here
        return result;
    }
};

class AutograderReducer : public Reducer
{
public:
    void Reduce(string &key, Input<float>* input) {
        float grade = input->value();
        output(key, grade);
    }
};