#include "LaunchTriggerBox.h"
#include "Components/PrimitiveComponent.h" 
#include "GameFramework/Character.h"
#include "Components/ShapeComponent.h" 

ALaunchTriggerBox::ALaunchTriggerBox()
{
	GetCollisionComponent()->OnComponentBeginOverlap.AddDynamic(this, &ALaunchTriggerBox::OnOverlapBegin);
	GetCollisionComponent()->OnComponentEndOverlap.AddDynamic(this, &ALaunchTriggerBox::OnOverlapEnd);

	GetCollisionComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GetCollisionComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetCollisionComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void ALaunchTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}

void ALaunchTriggerBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
	OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	ACharacter* Character = Cast<ACharacter>(OtherActor);

	if (Character)
	{
		Character->LaunchCharacter(LaunchVelocity, bXYOverride, bZOverride);
	}
}

void ALaunchTriggerBox::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
	OtherBodyIndex)
{

}