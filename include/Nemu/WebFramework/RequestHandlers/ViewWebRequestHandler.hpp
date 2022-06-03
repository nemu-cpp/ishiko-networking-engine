/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_VIEWWEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_VIEWWEBREQUESTHANDLER_HPP_

#include "../MapViewContext.hpp"
#include "../WebRequestHandler.hpp"
#include <boost/optional.hpp>
#include <Ishiko/Errors.hpp>
#include <string>

namespace Nemu
{
    
class ViewWebRequestHandler : public WebRequestHandler
{
public:
    class Callbacks
    {
    public:
        virtual ~Callbacks() = default;

        virtual std::string getView(const WebRequest& request, Ishiko::Error& error) = 0;
        // TODO: ultimately this is what I want I think but until I make ViewContext an interface this would involve
        // too much copying
        //virtual ViewContext getContext(const WebRequest& request, Ishiko::Error& error) const = 0;
    };

    class PrefixMappingCallbacks : public Callbacks
    {
    public:
        std::string getView(const WebRequest& request, Ishiko::Error& error) override;
    };

    ViewWebRequestHandler(Callbacks& callbacks);
    ViewWebRequestHandler(Callbacks& callbacks, std::string layout);

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

    const MapViewContext& context() const noexcept;
    MapViewContext& context() noexcept;

private:
    Callbacks& m_callbacks;
    boost::optional<std::string> m_layout;
    MapViewContext m_context;
};

}

#endif
