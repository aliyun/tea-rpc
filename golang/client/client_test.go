package client

import (
	"fmt"
	"net/http"
	"net/http/httptest"
	"strings"
	"testing"

	util "github.com/alibabacloud-go/tea-utils/service"
	"github.com/alibabacloud-go/tea/tea"
	"github.com/alibabacloud-go/tea/utils"
	credential "github.com/aliyun/credentials-go/credentials"
)

func mockServer(status int, json string) (server *httptest.Server) {
	// Start a test server locally.
	ts := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		w.WriteHeader(status)
		w.Write([]byte(json))
		return
	}))
	return ts
}

func Test_DoRequest(t *testing.T) {
	conf := new(credential.Config)
	conf.AccessKeyId = tea.String("accesskey_id")
	conf.AccessKeySecret = tea.String("accesskey_secret")
	conf.Type = tea.String("access_key")
	c, err := credential.NewCredential(conf)
	utils.AssertNil(t, err)

	config := new(Config).SetRegionId("域名")
	_, err = NewClient(config)
	utils.AssertNotNil(t, err)
	utils.AssertEqual(t, err.Error(), "域名 is not matched ^[a-zA-Z0-9_-]+$")

	_, err = NewClient(nil)
	utils.AssertNotNil(t, err)
	utils.AssertEqual(t, err.Error(), "SDKError:\n   Code: ParameterMissing\n   Message: 'config' can not be unset\n   Data: \n")

	config.SetRegionId("cn-hangzhou")
	_, err = NewClient(config)
	utils.AssertNotNil(t, err)
	utils.AssertEqual(t, err.Error(), "SDKError:\n   Code: ParameterMissing\n   Message: 'accessKeyId' and 'accessKeySecret' or 'credential' can not be unset\n   Data: \n")

	config.SetCredential(c)
	_, err = NewClient(config)
	utils.AssertNil(t, err)

	config.SetAccessKeyId("accesskey_id").
		SetAccessKeySecret("accesskey_secret")
	_, err = NewClient(config)
	utils.AssertNil(t, err)

	config.SetSecurityToken("SecurityToken")
	_, err = NewClient(config)
	utils.AssertNil(t, err)

	utils.AssertEqual(t, fmt.Sprintln(config), fmt.Sprintln(config.GoString()))

	config.SetProtocol("http").
		SetReadTimeout(10).
		SetConnectTimeout(10).
		SetHttpProxy("httpproxy").
		SetHttpsProxy("httpsproxy").
		SetEndpoint("endpoint").
		SetNoProxy("npproxy").
		SetMaxIdleConns(1).
		SetNetwork("public").
		SetUserAgent("aliyun").
		SetSuffix("ali").
		SetSocks5NetWork("tcp").
		SetSocks5Proxy("proxy").
		SetType("access_key").
		SetEndpointType("inner").
		SetOpenPlatformEndpoint("endpoint")

	config.SetHttpProxy("").
		SetHttpsProxy("").
		SetSocks5NetWork("").
		SetSocks5Proxy("")
	client, err := NewClient(config)
	utils.AssertNil(t, err)
	utils.AssertNotNil(t, client)

	ts := mockServer(400, `{"Code": "杭州"}`)
	defer ts.Close()
	client.Endpoint = tea.String(strings.Replace(ts.URL, "http://", "", 1))
	runtime := new(util.RuntimeOptions)
	resp, err := client.DoRequest(tea.String("testApi"), tea.String("HTTP"), tea.String("GET"),
		tea.String("2019-12-12"), tea.String("AK"), nil, nil, runtime)
	utils.AssertNotNil(t, err)
	utils.AssertEqual(t, err.Error(), "SDKError:\n   Code: 杭州\n   Message: code: 400, <nil> request id: <nil>\n   Data: {\"Code\":\"杭州\"}\n")
	utils.AssertNil(t, resp)

	runtime.SetMaxAttempts(3).SetAutoretry(true).SetBackoffPeriod(1).SetBackoffPolicy("ok")
	resp, err = client.DoRequest(tea.String("testApi"), tea.String("HTTP"), tea.String("GET"),
		tea.String("2019-12-12"), tea.String("AK"), nil, map[string]interface{}{"test": "ok"}, runtime)
	utils.AssertNotNil(t, err)
	utils.AssertEqual(t, err.Error(), "SDKError:\n   Code: 杭州\n   Message: code: 400, <nil> request id: <nil>\n   Data: {\"Code\":\"杭州\"}\n")
	utils.AssertNil(t, resp)

	ts = mockServer(200, `{"Code": "杭州"}`)
	client.Endpoint = tea.String(strings.Replace(ts.URL, "http://", "", 1))
	resp, err = client.DoRequest(tea.String("testApi"), tea.String("HTTP"), tea.String("GET"),
		tea.String("2019-12-12"), tea.String("AK"), nil, map[string]interface{}{"test": "ok"}, runtime)
	utils.AssertNil(t, err)
	utils.AssertEqual(t, resp, map[string]interface{}{"Code": "杭州"})

	client.Credential = nil
	ak, err := client.GetAccessKeyId()
	utils.AssertNil(t, err)
	utils.AssertEqual(t, tea.StringValue(ak), "")

	secret, err := client.GetAccessKeySecret()
	utils.AssertNil(t, err)
	utils.AssertEqual(t, tea.StringValue(secret), "")

	token, err := client.GetSecurityToken()
	utils.AssertNil(t, err)
	utils.AssertEqual(t, tea.StringValue(token), "")

	err = client.CheckConfig(config)
	utils.AssertNil(t, err)

	config.SetEndpoint("")
	client.EndpointRule = tea.String("")
	err = client.CheckConfig(config)
	utils.AssertEqual(t, err.Error(), "SDKError:\n   Code: ParameterMissing\n   Message: 'config.endpoint' can not be empty\n   Data: \n")
}
