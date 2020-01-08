package com.aliyuncs.pop;

import com.aliyun.tea.TeaRequest;
import com.aliyun.tea.TeaResponse;
import com.aliyun.tea.utils.StringUtils;
import com.google.gson.Gson;

import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import javax.xml.bind.DatatypeConverter;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.text.SimpleDateFormat;
import java.util.*;

public class RPCClient {
    private final static String SEPARATOR = "&";
    public final static String URL_ENCODING = "UTF-8";
    private static final String ALGORITHM_NAME = "HmacSHA1";
    protected String _endpoint;
    protected String _authToken;
    protected String _regionId;
    protected String _protocol;
    private String accessKeyId;
    private String accessKeySecret;
    protected String _userAgent;
    protected static final String _defaultUserAgent;

    static {
        Properties sysProps = System.getProperties();
        String coreVersion = "";
        Properties props = new Properties();
        try {
            props.load(RPCClient.class.getClassLoader().getResourceAsStream("project.properties"));
            coreVersion = props.getProperty("sdk.project.version");
        } catch (IOException e) {
            e.printStackTrace();
        }
        _defaultUserAgent = String.format("AlibabaCloud (%s; %s) Java/%s %s/%s", sysProps.getProperty("os.name"), sysProps
                .getProperty("os.arch"), sysProps.getProperty("java.runtime.version"), "rpc-baseClient", coreVersion);
    }

    public RPCClient() {

    }

    public RPCClient(Map<String, Object> config) {
        this._endpoint = (String) config.get("endpoint");
        this._authToken = (String) config.get("authToken");
        this.accessKeyId = (String) config.get("accessKeyId");
        this.accessKeySecret = (String) config.get("accessKeySecret");
        this._userAgent = (String) config.get("userAgent");
        this._protocol = config.get("protocol") == null ? "http" : (String) config.get("protocol");
        this._regionId = (String) config.get("regionId");
    }


    public int _defaultNumber(Object o, int number) {
        return o == null ? number : (int) o;
    }

    public String _default(Object o, String str) {
        return o == null ? str : String.valueOf(o);
    }

    public Map<String, String> _query(Map<String, Object> map) {
        Map<String, String> outMap = new HashMap<>(16);
        map.forEach((k, v) -> outMap.put(k, v == null ? "" : String.valueOf(v)));
        return outMap;
    }

    public String _getTimestamp() {
        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss'Z'");
        df.setTimeZone(new SimpleTimeZone(0, "UTC"));
        return df.format(new Date());
    }

    public String _getNonce() {
        StringBuffer uniqueNonce = new StringBuffer();
        UUID uuid = UUID.randomUUID();
        uniqueNonce.append(uuid.toString());
        uniqueNonce.append(System.currentTimeMillis());
        uniqueNonce.append(Thread.currentThread().getId());
        return uniqueNonce.toString();
    }

    public String _getSignature(TeaRequest request, String secret) throws UnsupportedEncodingException, NoSuchAlgorithmException, InvalidKeyException {
        Map<String, String> queries = request.query;
        String[] sortedKeys = queries.keySet().toArray(new String[]{});
        Arrays.sort(sortedKeys);
        StringBuilder canonicalizedQueryString = new StringBuilder();

        for (String key : sortedKeys) {
            canonicalizedQueryString.append("&")
                    .append(this.percentEncode(key)).append("=")
                    .append(this.percentEncode(queries.get(key)));
        }
        StringBuilder stringToSign = new StringBuilder();
        stringToSign.append(request.method);
        stringToSign.append(SEPARATOR);
        stringToSign.append(this.percentEncode("/"));
        stringToSign.append(SEPARATOR);
        stringToSign.append(this.percentEncode(
                canonicalizedQueryString.toString().substring(1)));
        System.out.println(stringToSign);
        Mac mac = Mac.getInstance(ALGORITHM_NAME);
        mac.init(new SecretKeySpec((secret + SEPARATOR).getBytes(URL_ENCODING), ALGORITHM_NAME));
        byte[] signData = mac.doFinal(stringToSign.toString().getBytes(URL_ENCODING));
        return DatatypeConverter.printBase64Binary(signData);
    }

    public String percentEncode(String value) throws UnsupportedEncodingException {
        return value != null ? URLEncoder.encode(value, URL_ENCODING).replace("+", "%20")
                .replace("*", "%2A").replace("%7E", "~") : null;
    }

    public String _getAccessKeyId() {
        return this.accessKeyId;
    }

    public String _getEndpoint(String str, String regionId) {
        if (null == _endpoint) {
            String serviceCode = str.split("_")[0].toLowerCase();
            return String.format("%s.%s.aliyuncs.com", serviceCode, regionId);
        } else {
            return _endpoint;
        }
    }


    public String _getAccessKeySecret() {
        return this.accessKeySecret;
    }

    public boolean _hasError(Map<String, Object> body) {
        if (null == body) {
            return true;
        }
        return null != body.get("Code");
    }

    public Map<String, Object> _json(TeaResponse response) throws IOException {
        Gson gson = new Gson();
        Map<String, Object> map = gson.fromJson(response.getResponseBody(), Map.class);
        return map;
    }

    protected String _getUserAgent() {
        return this._getUserAgent(null);
    }

    protected String _getUserAgent(String a) {
        if (StringUtils.isEmpty(a)) {
            return _defaultUserAgent;
        }
        return _defaultUserAgent + " " + a;
    }
}
