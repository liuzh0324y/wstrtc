#include "recorder.hh"

Recorder::Recorder() 
{
    _stopped = false;
    _storageDir = "./";
    _engine = NULL;
}

Recorder::~Recorder()
{

}
const char * Recorder::Out()
{
    return "recorder::out";
}

bool Recorder::createChannel(const std::string &appid, const std::string &channelKey, const std::string &channelId,  agora::linuxsdk::uid_t uid,
                agora::recording::RecordingConfig &config, callback b)
{
    if ((_engine = agora::recording::IRecordingEngine::createAgoraRecordingEngine(appid.c_str(), this)) == NULL)
        return false;

    if(agora::linuxsdk::ERR_OK != _engine->joinChannel(channelKey.c_str(), channelId.c_str(), uid, config))
        return false;

    _channelId = channelId;
    _config = config;
    _callback = b;
    return true;
}

bool Recorder::leaveChannel()
{
    if (_engine) {
        _engine->leaveChannel();
        _stopped = true;
    }

    return true;
}
/**
 *  Callback when an error occurred during the runtime of recording engine
 *
 *
 *  @param error        Error code
 *  @param stat_code    state code
 *
 */
void Recorder::onError(int error, agora::linuxsdk::STAT_CODE_TYPE stat_code)
{
    _callback(_channelId.c_str(), stat_code);
}

/**
 *  Callback when an warning occurred during the runtime of recording engine
 *
 *
 *  @param warn         warning code
 *
 */
void Recorder::onWarning(int warn)
{

}

/**
 *  Callback when the user hase successfully joined the specified channel
 *
 *
 *  @param channelID    channel ID 
 *  @param uid          User ID
 *
 */
void Recorder::onJoinChannelSuccess(const char * channelId, uid_t uid)
{
    // _callback(_channelId.c_str(), stat_code);
}

/**
 *  Callback when recording application successfully left the channel
 *
 *
 *  @param code        leave path code
 *
 */
void Recorder::onLeaveChannel(agora::linuxsdk::LEAVE_PATH_CODE code)
{
    
}

/**
 *  Callback when another user successfully joined the channel
 *
 *
 *  @param uid          user ID
 *  @param infos        user join information    
 *
 */
void Recorder::onUserJoined(uid_t uid, agora::linuxsdk::UserJoinInfos &infos)
{

}

/**
 *  Callback when a user left the channel or gone offline
 *
 *
 *  @param uid          user ID
 *  @param reason       offline reason    
 *
 */
void Recorder::onUserOffline(uid_t uid, agora::linuxsdk::USER_OFFLINE_REASON_TYPE reason)
{

}

/**
 *  Callback when received a audio frame
 *
 *
 *  @param uid          user ID
 *  @param frame        pointer to received audio frame    
 *
 */
void Recorder::audioFrameReceived(unsigned int uid, const agora::linuxsdk::AudioFrame *frame) const
{

}

/**
 *  Callback when received a video frame
 *
 *
 *  @param uid          user ID
 *  @param frame        pointer to received video frame    
 *
 */
void Recorder::videoFrameReceived(unsigned int uid, const agora::linuxsdk::VideoFrame *frame) const
{

}