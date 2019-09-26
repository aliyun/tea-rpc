package com.aliyuncs.pop;

import com.aliyun.tea.TeaRequest;
import com.aliyun.tea.TeaResponse;
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
    protected String _domain;
    protected String _authToken;
    protected String _regionId;
    protected String _protocol;
    private String accessKeyId;
    private String accessKeySecret;

    public RPCClient() {

    }

    public RPCClient(Map<String, String> config) {
        this._domain = config.get("domain");
        this._authToken = config.get("authToken");
        this.accessKeyId = config.get("accessKeyId");
        this.accessKeySecret = config.get("accessKeySecret");
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
        if (null == _domain) {
            String serviceCode = str.split("_")[0].toLowerCase();
            return String.format("%s.%s.aliyuncs.com", serviceCode, regionId);
        } else {
            return _domain;
        }
    }


    public String _getAccessKeySecret() {
        return this.accessKeySecret;
    }

    public boolean _hasError(Map<String, Object> body) {
        if (null == body) {
            return true;
        }
        if (null == body.get("code")) {
            return false;
        }
        return true;
    }

    public Map<String, Object> _json(TeaResponse response) throws IOException {
        Gson gson = new Gson();
        Map<String, Object> map = gson.fromJson(response.getResponseBody(), Map.class);
        return map;
    }
}
