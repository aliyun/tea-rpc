// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.tearpc.models;

import com.aliyun.tea.*;

/**
 * Model for initing client
 */
public class Config extends TeaModel {
    @NameInMap("accessKeyId")
    public String accessKeyId;

    @NameInMap("accessKeySecret")
    public String accessKeySecret;

    @NameInMap("securityToken")
    public String securityToken;

    @NameInMap("protocol")
    public String protocol;

    @NameInMap("regionId")
    @Validation(pattern = "^[a-zA-Z0-9_-]+$")
    public String regionId;

    @NameInMap("readTimeout")
    public Integer readTimeout;

    @NameInMap("connectTimeout")
    public Integer connectTimeout;

    @NameInMap("httpProxy")
    public String httpProxy;

    @NameInMap("httpsProxy")
    public String httpsProxy;

    @NameInMap("credential")
    public com.aliyun.credentials.Client credential;

    @NameInMap("endpoint")
    public String endpoint;

    @NameInMap("noProxy")
    public String noProxy;

    @NameInMap("maxIdleConns")
    public Integer maxIdleConns;

    @NameInMap("network")
    @Validation(pattern = "^[a-zA-Z0-9_-]+$")
    public String network;

    @NameInMap("userAgent")
    public String userAgent;

    @NameInMap("suffix")
    @Validation(pattern = "^[a-zA-Z0-9_-]+$")
    public String suffix;

    @NameInMap("socks5Proxy")
    public String socks5Proxy;

    @NameInMap("socks5NetWork")
    public String socks5NetWork;

    @NameInMap("endpointType")
    public String endpointType;

    @NameInMap("openPlatformEndpoint")
    public String openPlatformEndpoint;

    @NameInMap("type")
    @Deprecated
    public String type;

    public static Config build(java.util.Map<String, ?> map) throws Exception {
        Config self = new Config();
        return TeaModel.build(map, self);
    }

}
