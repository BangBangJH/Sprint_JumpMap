#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PullableComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRINT_JUMPMAP_API UPullableComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPullableComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void StartPulling(const FVector& PullerLocation, float PullerForce);
	void StopPulling();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<UPrimitiveComponent> Root;

	UPROPERTY()
	bool bIsPulling = false;

	UPROPERTY()
	FVector TargetLocation;

	UPROPERTY()
	float PullingForce = .0f;
};