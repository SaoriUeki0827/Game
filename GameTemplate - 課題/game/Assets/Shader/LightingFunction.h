/*!
 * @brief	ライティング関係の関数集
 */

#define NUM_DIFFUSE_LIGHT	4					//ディフューズライトの数。

float3 g_vEyePt;
struct SLight{
	float4	diffuseLightDir[NUM_DIFFUSE_LIGHT];		//ディフューズライトの向き。
	float4  diffuseLightColor[NUM_DIFFUSE_LIGHT];	//ディフューズライトのカラー。
	float4  ambient;								//アンビエントライト。
};
SLight	g_light;		//ライト

/*!
*@brief	ディフューズライトを計算。
*/
float4 DiffuseLight(float3 normal)
{
	float4 color = 0.0f;
	for (int i = 0; i < NUM_DIFFUSE_LIGHT; i++){
		color += max(0, -dot(normal, g_light.diffuseLightDir[i])) * g_light.diffuseLightColor[i];
	}
	color.xyz += g_light.ambient.xyz;
	color.a = 1.0f;
	return color;
}
/*!
*@brief	スペキュラライトを計算。
*/
float4 SpecularLight(float3 normal,float3 pos)
{
	float4 specla = 0.0f;
	float3 eye = normalize(g_vEyePt - pos);
	float3 R = -eye + 2.0f*dot(normal, eye)*normal;
	for (int i = 0; i < NUM_DIFFUSE_LIGHT; i++){
		float3 spec = max(0.0f, dot(R, -g_light.diffuseLightDir[i].xyz));
		specla.xyz += pow(spec, 5.0f);
	}
	return specla;
}

/*!
 * @brief	アルファに埋め込む輝度を計算。
 */
float CalcLuminance( float3 color )
{
	float luminance = dot( color.xyz, float3(0.2125f, 0.7154f, 0.0721f) );
	if(luminance > 1.0f ){
		luminance = 1.0f / luminance;
	}else{
		luminance = 0.0f;
	}
	return luminance;
}