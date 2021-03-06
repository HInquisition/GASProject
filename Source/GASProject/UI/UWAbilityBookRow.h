// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UWAbilityBookSlot.h"
#include "Blueprint/UserWidget.h"
#include "Characters/AGPlayerCharacter.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "GAS/AGGameplayAbilityBase.h"
#include "UWAbilityBookRow.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UUWAbilityBookRow : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUWAbilityBookSlot> AbilitySlotClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget = "PossibleAbilitiesPanel"))
	UHorizontalBox* PossibleAbilitiesPanel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget = "SelectedAbilityIcon"))
	UImage* SelectedAbilityIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "InputBinding")
	TEnumAsByte<EGDAbilityInputID> InputBind;

	UFUNCTION(BlueprintCallable)
	void GeneratePossibleAbilities();

	UFUNCTION(BlueprintCallable)
	void InitializeChildrenSlots();

	UFUNCTION()
	void SetAbility(const TSubclassOf<UAGGameplayAbilityBase> AbilityClass);

protected:

	virtual void NativeOnInitialized() override;

};
