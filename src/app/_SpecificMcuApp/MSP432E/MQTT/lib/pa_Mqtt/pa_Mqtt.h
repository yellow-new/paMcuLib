#include "pa_CommonLib/src/drv/pa_CommonDrv/pa_CommonDrv.h"
#ifdef __cplusplus
extern "C"
{
#endif
    void pa_Mqtt_publish(char *topic, uint16_t topicLen, char *data, uint16_t dataLen);
#ifdef __cplusplus
}
#endif