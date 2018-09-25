#include "recorder.hh"

Recorder::Recorder() 
{
    m_stopped = false;
    m_storage_dir = "./";
    m_engine = NULL;
}

Recorder::~Recorder()
{

}
const char * Recorder::Out()
{
    return "recorder::out";
}

bool Recorder::createChannel(const std::string &appid, const std::string &channelKey, const std::string &name,  agora::linuxsdk::uid_t uid,
                agora::recording::RecordingConfig &config)
{
    if ((m_engine = agora::recording::IRecordingEngine::createAgoraRecordingEngine(appid.c_str(), this)) == NULL)
        return false;

    if(agora::linuxsdk::ERR_OK != m_engine->joinChannel(channelKey.c_str(), name.c_str(), uid, config))
        return false;

    m_config = config;
    return true;
}

bool Recorder::leaveChannel()
{
    if (m_engine) {
        m_engine->leaveChannel();
        m_stopped = true;
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