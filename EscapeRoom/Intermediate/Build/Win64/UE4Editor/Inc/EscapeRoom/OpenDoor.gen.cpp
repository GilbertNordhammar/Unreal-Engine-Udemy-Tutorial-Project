// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EscapeRoom/OpenDoor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOpenDoor() {}
// Cross Module References
	ESCAPEROOM_API UClass* Z_Construct_UClass_UOpenDoor_NoRegister();
	ESCAPEROOM_API UClass* Z_Construct_UClass_UOpenDoor();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_EscapeRoom();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerVolume_NoRegister();
// End Cross Module References
	void UOpenDoor::StaticRegisterNativesUOpenDoor()
	{
	}
	UClass* Z_Construct_UClass_UOpenDoor_NoRegister()
	{
		return UOpenDoor::StaticClass();
	}
	struct Z_Construct_UClass_UOpenDoor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__pressurePlateWeigthThreshold_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__pressurePlateWeigthThreshold;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__openAngle_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__openAngle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__pressurePlate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__pressurePlate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOpenDoor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_EscapeRoom,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOpenDoor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "OpenDoor.h" },
		{ "ModuleRelativePath", "OpenDoor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlateWeigthThreshold_MetaData[] = {
		{ "Category", "OpenDoor" },
		{ "ModuleRelativePath", "OpenDoor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlateWeigthThreshold = { UE4CodeGen_Private::EPropertyClass::Float, "_pressurePlateWeigthThreshold", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000001, 1, nullptr, STRUCT_OFFSET(UOpenDoor, _pressurePlateWeigthThreshold), METADATA_PARAMS(Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlateWeigthThreshold_MetaData, ARRAY_COUNT(Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlateWeigthThreshold_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOpenDoor_Statics::NewProp__openAngle_MetaData[] = {
		{ "Category", "OpenDoor" },
		{ "ModuleRelativePath", "OpenDoor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOpenDoor_Statics::NewProp__openAngle = { UE4CodeGen_Private::EPropertyClass::Float, "_openAngle", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000001, 1, nullptr, STRUCT_OFFSET(UOpenDoor, _openAngle), METADATA_PARAMS(Z_Construct_UClass_UOpenDoor_Statics::NewProp__openAngle_MetaData, ARRAY_COUNT(Z_Construct_UClass_UOpenDoor_Statics::NewProp__openAngle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlate_MetaData[] = {
		{ "Category", "OpenDoor" },
		{ "ModuleRelativePath", "OpenDoor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlate = { UE4CodeGen_Private::EPropertyClass::Object, "_pressurePlate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000001, 1, nullptr, STRUCT_OFFSET(UOpenDoor, _pressurePlate), Z_Construct_UClass_ATriggerVolume_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOpenDoor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlateWeigthThreshold,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOpenDoor_Statics::NewProp__openAngle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOpenDoor_Statics::NewProp__pressurePlate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOpenDoor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOpenDoor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UOpenDoor_Statics::ClassParams = {
		&UOpenDoor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A0u,
		nullptr, 0,
		Z_Construct_UClass_UOpenDoor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UOpenDoor_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UOpenDoor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UOpenDoor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOpenDoor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UOpenDoor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOpenDoor, 4195098991);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOpenDoor(Z_Construct_UClass_UOpenDoor, &UOpenDoor::StaticClass, TEXT("/Script/EscapeRoom"), TEXT("UOpenDoor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOpenDoor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
