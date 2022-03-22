/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoWebRequest.hpp"

using namespace boost;
using namespace std;

namespace Nemu
{

string IshikoWebRequest::URI() const
{
    return m_uri;
}

void IshikoWebRequest::onRequestURI(string_view data)
{
    m_uri = data.to_string();
}

}
