/* ---------------------------------------
 * Code modified from Ian Kuo, 2013/12/7.
 * --------------------------------------- */

#ifndef PARTICLEFILTER_PARTICLEFILTER_H
#define PARTICLEFILTER_PARTICLEFILTER_H

#include <vector>
using namespace std;

class Scene;

struct ParticleType    {
    //int            position[3];        // [x, y, z]
    double        position[3];
    double        azimuth;
    double        elevation;
    double        weight;
    double        oldweight;
};

class ParticleFilter {
public:
    ParticleFilter(void);
    ~ParticleFilter(void);
    void initialize(Scene* scene);
    void update();
    vector<ParticleType*>* getNewSampleVec();

    // Temporary
    void setCallbackParticleEvaluation(double (*cb)(double, double, double));

private:
    //Graphics^ g;
    //Pen^ _skyBluePen;
    //Pen^ _RedPen;
    //Pen^ _BlackPen;

    Scene *sceneMain;

    //Projector^ _Proj;

    vector<ParticleType*>* _OldSampleVec;
    vector<ParticleType*>* _NewSampleVec;

    double *_RangeOfScene;
    double *_SceneSize;

    int _sampleNum;
    double _threshold;
    double _variance;

    int _Length;
    int _Width;
    int _Height;

    // Temporary
    double (*callbackParticleEvaluation)(double, double, double);
};

#endif