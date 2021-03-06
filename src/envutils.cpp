#include "envutils.h"

#include <QProcessEnvironment>

void Mere::Utils::EnvUtils::expandEnvVar(std::string &str)
{
    QProcessEnvironment processEnvironment = QProcessEnvironment::systemEnvironment();

    QStringList keys = processEnvironment.keys();
    for(QString key : keys)
    {
        std::string env("$");
        env.append(key.toStdString());

        auto pos = str.find(env);
        if (pos != std::string::npos)
        {
            QString val = processEnvironment.value(key);
            str = str.replace(pos, env.length(), val.toStdString());
        }
    }
}
