// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Assignment06/Public/RotateFloor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRotateFloor() {}

// Begin Cross Module References
ASSIGNMENT06_API UClass* Z_Construct_UClass_ARotateFloor();
ASSIGNMENT06_API UClass* Z_Construct_UClass_ARotateFloor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Assignment06();
// End Cross Module References

// Begin Class ARotateFloor
void ARotateFloor::StaticRegisterNativesARotateFloor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARotateFloor);
UClass* Z_Construct_UClass_ARotateFloor_NoRegister()
{
	return ARotateFloor::StaticClass();
}
struct Z_Construct_UClass_ARotateFloor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "RotateFloor.h" },
		{ "ModuleRelativePath", "Public/RotateFloor.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARotateFloor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARotateFloor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Assignment06,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARotateFloor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARotateFloor_Statics::ClassParams = {
	&ARotateFloor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARotateFloor_Statics::Class_MetaDataParams), Z_Construct_UClass_ARotateFloor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARotateFloor()
{
	if (!Z_Registration_Info_UClass_ARotateFloor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARotateFloor.OuterSingleton, Z_Construct_UClass_ARotateFloor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARotateFloor.OuterSingleton;
}
template<> ASSIGNMENT06_API UClass* StaticClass<ARotateFloor>()
{
	return ARotateFloor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARotateFloor);
ARotateFloor::~ARotateFloor() {}
// End Class ARotateFloor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Assignment06_Source_Assignment06_Public_RotateFloor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARotateFloor, ARotateFloor::StaticClass, TEXT("ARotateFloor"), &Z_Registration_Info_UClass_ARotateFloor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARotateFloor), 1526574450U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Assignment06_Source_Assignment06_Public_RotateFloor_h_4276073749(TEXT("/Script/Assignment06"),
	Z_CompiledInDeferFile_FID_Assignment06_Source_Assignment06_Public_RotateFloor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Assignment06_Source_Assignment06_Public_RotateFloor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
