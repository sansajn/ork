#include "ork/scenegraph/CallMethodTask.h"
#include "ork/scenegraph/DrawMeshTask.h"
#include "ork/scenegraph/LoopTask.h"
#include "ork/scenegraph/SequenceTask.h"
#include "ork/scenegraph/SetStateTask.h"
#include "ork/scenegraph/SetProgramTask.h"
#include "ork/scenegraph/SetTargetTask.h"
#include "ork/scenegraph/SetTransformsTask.h"

namespace ork {

void InitResourceTypes() {
    // scenegraph resources
    ork::registerCallMethodResource();
    ork::registerDrawMeshResource();
    ork::registerLoopResource();
    ork::registerSequenceResource();
    ork::registerSetProgramResource();
    ork::registerSetStateResource();
    ork::registerSetTargetResource();
    ork::registerSetTransformsResource();
}

}  // ork
