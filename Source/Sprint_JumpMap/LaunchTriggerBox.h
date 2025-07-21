#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LaunchTriggerBox.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRINT_JUMPMAP_API ALaunchTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
public:
	ALaunchTriggerBox();
	virtual void BeginPlay() override;
private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
		OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
		OtherBodyIndex);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Launch", meta = (AllowPrivateAccess="true"))
	FVector LaunchVelocity = FVector(0.f, 0.f, 1000.f); 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Launch", meta = (AllowPrivateAccess = "true"))
	bool bXYOverride = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Launch", meta = (AllowPrivateAccess = "true"))
	bool bZOverride = true; 
};
