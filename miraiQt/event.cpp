#include "event.h"

Event::Event() : QObject(){
}

MessageEvent::MessageEvent() : Event(){
}

NoticeEvent::NoticeEvent() : Event(){
}

RequestEvent::RequestEvent() : Event(){
}

MetaEvent::MetaEvent() : Event(){
}

