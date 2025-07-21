#include "PullableComponent.h"

UPullableComponent::UPullableComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UPullableComponent::BeginPlay()
{
	Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	if (Root)
	{
		Root->SetSimulatePhysics(true);
		Root->SetGenerateOverlapEvents(true);

		Root->SetCollisionObjectType(ECC_GameTraceChannel3);
		Root->SetCollisionResponseToAllChannels(ECR_Block);
		Root->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);
	}
}

void UPullableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Cyan, TEXT("PullableComponent Ticking..."));

	if (bIsPulling && Root)
	{
		const FVector ForceDirection = TargetLocation - GetOwner()->GetActorLocation();
		const FVector ForceToApply = ForceDirection * PullingForce;
		Root->AddForce(ForceToApply);
	}
}

void UPullableComponent::StartPulling(const FVector& PullerLocation, float PullerForce)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("StartPulling Called!"));

	TargetLocation = PullerLocation;
	PullingForce = PullerForce;
	bIsPulling = true;
	SetComponentTickEnabled(true); 
}

void UPullableComponent::StopPulling()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("StopPulling Called!"));
	bIsPulling = false;
	SetComponentTickEnabled(false);
}